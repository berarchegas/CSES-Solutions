// Tree Matching
//
// Problem name: Tree Matching
// Problem Link: https://cses.fi/problemset/task/1130
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
int dp[MAXN][2];
 
void dfs(int node, bool flag, int pai) {
	if (dp[node][flag] > -1) return;
	vector<int> zero, um;
	int ans = 0;
	for (int x : v[node]) {
		if (x != pai) {
			if (flag) {
				dfs(x, false, node);
				ans += dp[x][0];
			}
			else {
				dfs(x, false, node);
				dfs(x, true, node);
				zero.pb(dp[x][0]);
				um.pb(1 + dp[x][1]);
			}
		}
	}
	if (!flag) {
		int tam = (int)zero.size(), total = 0;
		for (int i = 0; i < tam; i++) {
			total += zero[i];
		}
		for (int i = 0; i < tam; i++) {
			ans = max(ans, um[i] + total - zero[i]);
		}
	}
	dp[node][flag] = ans;
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
	memset(dp, -1, sizeof(dp));
	dfs(1, 0, 0);
	cout << dp[1][0] << '\n';
	return 0;	
}