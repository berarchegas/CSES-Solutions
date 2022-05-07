/*
Problem Name: Path Queries
Problem Link: https://cses.fi/problemset/task/1138
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
 
vector<int> v[MAXN], a(1);
int sz[MAXN], pos[MAXN];
ll ini[MAXN], val[MAXN];
vector<ll> dif(MAXN);
 
void dfs(int node, int pai) {
    sz[node] = 1;
    ini[node] = ini[pai] + val[node];
    a.pb(node);
    pos[node] = (int)a.size()-1;
    for (int x : v[node]) {
        if (x != pai) {
            dfs(x, node);
            sz[node] += sz[x];
        }
    }
}
 
ll sum(int pos) {
    ll resp = 0;
    for (int i = pos; i > 0; i -= (i & -i)) {
        resp += dif[i];
    }
    return resp;
}
 
void upd(int pos, ll value) {
    for (int i = pos; i < MAXN; i += (i & -i)) {
        dif[i] += value;
    }
}
 
int main () { _
    int n, m, x, y, z;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1, 0);
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (x == 1) {
            cin >> y >> z;
            upd(pos[y], z - val[y]);
            upd(pos[y] + sz[y], val[y] - z);
            val[y] = z;
        }
        if (x == 2) {
            cin >> y;
            cout << ini[y] + sum(pos[y]) << '\n';
        }
    }
	return 0;	
}