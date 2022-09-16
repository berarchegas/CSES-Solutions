// Forest Queries
//
// Problem name: Forest Queries
// Problem Link: https://cses.fi/problemset/task/1652
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1010
#define INF 100000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
 
int bit[MAXN][MAXN], n;
 
int soma (int x, int y) {
	int resp = 0;
	for (int i = x; i > 0; i -= (i & -i)) {
		for (int j = y; j > 0; j -= (j & -j)) {
			resp += bit[i][j];
		}
	}
	return resp;
}
 
void update (int x, int y) {
	for (int i = x; i < 1001; i += (i&-i)) {
		for (int j = y; j < 1001; j += (j & -j)) {
			bit[i][j] += 1;
		}
	}
}
 
int main () { _
	int q, x1, y1, x2, y2;
	char c;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			if (c == '*') update(i, j);
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		cout << soma(y2, x2) - soma(y1-1, x2) - soma(y2, x1-1) + soma(y1-1, x1-1) << endl;
	}
    return 0;	
}