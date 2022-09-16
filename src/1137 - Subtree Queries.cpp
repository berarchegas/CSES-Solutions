// Subtree Queries
//
// Problem name: Subtree Queries
// Problem Link: https://cses.fi/problemset/task/1137
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
 
vector<int> v[MAXN], a(1, 0);
int val[MAXN], sz[MAXN], pos[MAXN];
ll t[MAXN];
 
ll sum(int pos) {
	ll resp = 0;
	for (int i = pos; i > 0; i -= (i & -i)) {
		resp += t[i];
	}
	return resp;
}
 
void upd(int pos, int val) {
	for (int i = pos; i < MAXN; i += (i & -i)) {
		t[i] += val;
	}
}
 
void dfs(int node, int pai) {
	sz[node] = 1;
	a.pb(node);
	pos[node] = (int)a.size()-1;
	upd(pos[node], val[node]);
	for (int x : v[node]) {
		if (x != pai) {
			dfs(x, node);
			sz[node] += sz[x];
		}
	}
}
 
int main () { _
	int n, q, x, y, z;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> val[i];
	}
	for (int i = 0; i < n-1; i++) {
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1, 0);
	for (int i = 0; i < q; i++) {
		cin >> x;
		if (x == 1) {
			cin >> y >> z;
			upd(pos[y], z - val[y]);
			val[y] = z;
		}
		else {
			cin >> y;
			cout << sum(pos[y] + sz[y] - 1) - sum(pos[y]-1) << '\n';
		}
	}
	return 0;	
}