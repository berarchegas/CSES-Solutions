// Tree Distances I
//
// Problem name: Tree Distances I
// Problem Link: https://cses.fi/problemset/task/1132
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 1000000001
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9+7;
 
vector<int> v[MAXN];
pair<pii, pii> dp[MAXN];
int ans[MAXN];
 
void dfs(int node, int pai) {
	for (int x : v[node]) {
		if (x != pai) {
			dfs(x, node);
			if (dp[x].F.F+1 > dp[node].F.F) {
				dp[node].S = dp[node].F;
				dp[node].F = {dp[x].F.F+1, x};
			}
			else if (dp[x].F.F+1 > dp[node].S.F) {
				dp[node].S = {dp[x].F.F+1, x};
			}
		}
	}
}
 
void dfs2(int node, int pai) {
	for (int x : v[node]) {
		if (x != pai) {
			if (dp[node].F.S == x) {
				ans[x] = max(dp[node].S.F, ans[node]) + 1;
			}
			else {
				ans[x] = max(dp[node].F.F, ans[node]) + 1;
			}
			dfs2(x, node);
		}
	}
}
 
int main () { _
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++) cout << max(dp[i].F.F, ans[i]) << ' ';
	cout << '\n';
	return 0;	
}