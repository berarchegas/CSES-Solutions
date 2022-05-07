/*
Problem Name: Edge Directions
Problem Link: https://cses.fi/problemset/task/1756
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
const int M = 1e9+7;
 
vector<int> v[MAXN];
vector<pii> edg;
int lvl[MAXN];
 
void dfs(int node, int pai) {
	lvl[node] = lvl[pai]+1;
	for (int x : v[node]) 
		if (!lvl[x]) dfs(x, node);
}
 
int main () { _
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
		edg.pb({a, b});
	}
	for (int i = 1; i <= n; i++) if (!lvl[i]) dfs(i, 0);
	for (pii x : edg) {
		if (lvl[x.F] > lvl[x.S]) cout << x.S << ' ' << x.F << '\n';
		else cout << x.F << ' ' << x.S << '\n';
	}
    return 0;
}