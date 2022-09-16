// Reachable Nodes
//
// Problem name: Reachable Nodes
// Problem Link: https://cses.fi/problemset/task/2138
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 50100
#define INF 1e17
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 998244353;
 
vector<int> v[MAXN], ord;
int check[MAXN];
bitset<MAXN> bits[MAXN];
 
void dfs(int node) {
	check[node] = 1;
	for (int x : v[node]) 
		if (!check[x]) dfs(x);
	ord.pb(node);
}
 
void dfs2(int node) {
	for (int x : v[node]) bits[node] |= bits[x];
}
 
int main() { _
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].pb(b);
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) dfs(i);
		bits[i].set(i);
	}
	for (int x : ord) dfs2(x);
	for (int i = 1; i <= n; i++) cout << bits[i].count() << ' ';
	cout << '\n';
    return 0;
}
