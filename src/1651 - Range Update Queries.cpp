// Range Update Queries
//
// Problem name: Range Update Queries
// Problem Link: https://cses.fi/problemset/task/1651
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 100000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
 
lli bit[MAXN], n;
 
lli soma (int x) {
	lli resp = 0;
	while (x > 0) {
		resp += bit[x];
		x -= (x & -x);
	}
	return resp;
}
 
void update (int x, int valor) {
	while (x <= n) {
		bit[x] += valor;
		x += (x & -x);
	}
}
 
int main () { _
	int q, tipo, a, b, c, anterior;
	cin >> n >> q;
	cin >> a;
	update (1, a);
	anterior = a;
	for (int i = 2; i <= n; i++) {
		cin >> a;
		update(i, a-anterior);
		anterior = a;
	}
	for (int i = 0; i < q; i++) {
		cin >> tipo;
		if (tipo == 1) {
			cin >> a >> b >> c;
			update(a, c);
			update(b+1, -c);
		}
		else {
			cin >> a;
			cout << soma(a) << endl;
		}
	}
    return 0;	
}