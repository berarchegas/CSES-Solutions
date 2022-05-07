/*
Problem Name: Finding a Centroid
Problem Link: https://cses.fi/problemset/task/2079
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 1e18
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M1 = 1e9+7, M2 = 998244353;
 
vector<int> v[MAXN];
int dp[MAXN], valid[MAXN], n;
 
void dfs(int node, int pai) {
	dp[node] = 1;
	bool ok = true;
	for (int x : v[node]) {
		if (x != pai) {
			dfs(x, node);
			dp[node] += dp[x];
			ok &= (dp[x] <= (n/2));
		}
	}
	ok &= (n - dp[node] <= (n/2));
	valid[node] = ok;
}
 
int main() { _
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++) 
		if (valid[i]) {
			cout << i << '\n';
			break;
		}
	return 0;
}