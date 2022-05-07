/*
Problem Name: Tree Distances II
Problem Link: https://cses.fi/problemset/task/1133
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
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
ll tam[MAXN], dp[MAXN], ans[MAXN], n;
 
void dfs(int node, int pai) {
	tam[node] = 1;
	for (int x : v[node]) {
		if (x != pai) {
			dfs(x, node);
			tam[node] += tam[x];
			dp[node] += tam[x] + dp[x];
		}
	}
}
 
void dfs2(int node, int pai) {
	ans[node] = ans[pai] + n - 2 * tam[node];
	for (int x : v[node]) 
		if (x != pai) dfs2(x, node);
}
 
int main () { _
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1, 0);
	ans[0] = dp[1] + 2*tam[1] - n;
	dfs2(1, 0);
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << '\n';
	return 0;	
}