// Company Queries II
//
// Problem name: Company Queries II
// Problem Link: https://cses.fi/problemset/task/1688
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
 
int tab[MAXN][25], nivel[MAXN];
vector<int> v[MAXN];
 
int lca(int a, int b) {
	if (nivel[a] < nivel[b]) swap(a, b);
	for (int i = 19; i >= 0; i--) {
		if (nivel[a] - nivel[b] >= (1<<i)) {
			a = tab[a][i];
		}
	}
	if (a == b) return a;
	for (int i = 19; i >= 0; i--) {
		if (tab[a][i] != tab[b][i]) {
			a = tab[a][i];
			b = tab[b][i];
		}
	}
	return tab[a][0];
}
 
void dfs(int node) {
	for (int i = 1; i < 20; i++) {
		tab[node][i] = tab[tab[node][i-1]][i-1];
	}
	for (int x : v[node]) {
		nivel[x] = nivel[node]+1;
		dfs(x);
	}
}
 
int main () { _
	int n, q;
	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		cin >> tab[i][0];
		v[tab[i][0]].pb(i);
	}
	nivel[1] = 1;
	dfs(1);
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
	return 0;	
}