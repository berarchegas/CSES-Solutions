// Counting Paths
//
// Problem name: Counting Paths
// Problem Link: https://cses.fi/problemset/task/1136
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
 
vector<int> v[MAXN], a;
int tab[MAXN][25], nivel[MAXN], ans[MAXN];
 
void dfs(int node, int pai) {
    a.pb(node);
    tab[node][0] = pai;
    nivel[node] = 1 + nivel[pai];
    for (int i = 1; i <= 20; i++) {
        tab[node][i] = tab[tab[node][i-1]][i-1];
    }
    for (int x : v[node])
        if (x != pai)   
            dfs(x, node);
}
 
void dfs2(int node, int pai) {
    for (int x : v[node]) {
        if (x != pai) {
            dfs2(x, node);
            ans[node] += ans[x];
        }
    }
}
 
int lca(int a, int b) {
    if (nivel[a] < nivel[b]) swap(a, b);
 
    for (int i = 20; i >= 0; i--) {
        if (nivel[a] - nivel[b] >= (1<<i)) {
            a = tab[a][i];
        }
    }
 
    if (a == b) return a;
 
    for (int i = 20; i >= 0; i--) {
        if (tab[a][i] != tab[b][i]) {
            a = tab[a][i];
            b = tab[b][i];
        }
    }
    return tab[a][0];
}
 
int main () { _
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1, 0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        ans[a]++;
        ans[b]++;
        int pater = lca(a, b);
        ans[pater]--;
        ans[tab[pater][0]]--;
    }
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
	return 0;	
}