// Restaurant Customers
//
// Problem name: Restaurant Customers
// Problem Link: https://cses.fi/problemset/task/1619
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1e5+2
#define INF 1000000001
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 998244353;
 
int main () { _
	int n, a;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.pb({a, 1});
		cin >> a;
		v.pb({a, 0});
	}
	sort(v.begin(), v.end());
	int ans = 0, atual = 0;
	for (int i = 0; i < 2*n; i++) {
		if (v[i].S) atual++;
		else atual--;
		ans = max(ans, atual);
	}
	cout << ans << '\n';
	return 0;
}