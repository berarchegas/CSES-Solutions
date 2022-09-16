// Josephus Queries
//
// Problem name: Josephus Queries
// Problem Link: https://cses.fi/problemset/task/2164
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1000100
#define INF 100000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9+7;
 
int jose(int n, int pos, bool impar) {
	if (n == 0) return 1;
	if (impar) {
		if (n&1) {
			if (pos <= n/2 + 1) return 2 * pos - 1;
			return 2 * jose(n/2, pos - n/2 - 1, false);
		}
		else {
			if (pos <= n/2) return 2 * pos - 1;
			return 2 * jose(n/2, pos - n/2, true);
		}
	}
	else {
		if (pos <= n/2) return 2 * pos;
		if (n&1) {
			return 2 * jose(n/2+1, pos - n/2, true) - 1;
		}
		else {
			return 2 * jose(n/2, pos - n/2, false) - 1;
		}
	}
}
 
int main () { _
	int q, n, k;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n >> k;
		cout << jose(n, k, false) << '\n';
	}
    return 0;   
}