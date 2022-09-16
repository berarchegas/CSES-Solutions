// School Excursion
//
// Problem name: School Excursion
// Problem Link: https://cses.fi/problemset/task/1706
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 100100
#define INF 1e18
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 1e9+7;
 
vector<int> v[MAXN], vals;
int vis[MAXN], cnt, dp[MAXN], used[MAXN], have[MAXN];
 
void dfs(int node) {
	cnt++;
	vis[node] = 1;
	for (int x : v[node]) 
		if (!vis[x]) dfs(x);
}
 
int main() { _
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt = 0;
			dfs(i);
			vals.pb(cnt);
		}
	}
	sort(vals.begin(), vals.end());
	for (int x : vals) have[x]++;
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	dp[0] = 1;
	for (int x : vals) {
		memset(used, 0, sizeof(used));
		for (int i = 0; i <= n; i++) {
			if (i + x > n) break;
			if (dp[i] && !dp[i+x] && used[i] < have[x]) {
				used[i+x] = used[i]+1;
				dp[i+x] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << dp[i];
	cout << '\n';
    return 0;
}