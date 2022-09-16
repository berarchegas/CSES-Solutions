// Subarray Sums II
//
// Problem name: Subarray Sums II
// Problem Link: https://cses.fi/problemset/task/1661
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 100100
#define INF 1000000001
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
 
int main() { _
    int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	if (!x) cout << 1ll * n * (n+1) / 2 << '\n';
	else {
		map<ll, ll> mapa;
		mapa[0] = 1;
		ll soma = 0, resp = 0;
		for (int i = 0; i < n; i++) {
			soma += v[i];
			mapa[soma]++;
			resp += mapa[soma - x];
		}
		cout << resp << '\n';
	}
    return 0;
}