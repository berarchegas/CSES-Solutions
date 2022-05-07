/*
Problem Name: Range Queries and Copies
Problem Link: https://cses.fi/problemset/task/1737
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 5e6 + 5;
const ll INF = 2e18;
 
ll esq[MAXN], dir[MAXN], a[MAXN];
int raiz[(int)2e5 + 5], v[(int)2e5 + 5], disp = 0, lst = 2;
 
void build(int node, int i, int j) {
    if (i == j) {
        a[node] = v[i];
        disp = max((int)disp, node);
    }
    else {
        int m = (i + j) / 2;
        build(2 * node, i, m);
        build(2 * node + 1, m + 1, j);
        esq[node] = 2 * node;
        dir[node] = 2 * node + 1;
        a[node] = a[2 * node] + a[2 * node + 1];
    }
}
 
ll query(int node, int i, int j, int ini, int fim) {
    if (i > fim || j < ini) return 0;
    else if (ini <= i && j <= fim) return a[node];
    else {
        int m = (i + j) / 2;
        return query(esq[node], i, m, ini, fim) + query(dir[node], m + 1, j, ini, fim);
    }
}
 
int upd(int node, int i, int j, int pos, int val) {
    int novo = disp++;
    if (i == j) {
        a[novo] = val;
        return novo;
    }
    int m = (i + j) / 2;
    if (m >= pos) {
        esq[novo] = upd(esq[node], i, m, pos, val);
        dir[novo] = dir[node];
    }
    else {
        dir[novo] = upd(dir[node], m + 1, j, pos, val);
        esq[novo] = esq[node];
    }
    a[novo] = a[esq[novo]] + a[dir[novo]];
    return novo;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> v[i];
    raiz[1] = 1;
    build(1, 1, n);
    disp++;
    int tipo, ar, x, y;
    for (int i = 0; i < q; i++) {
        cin >> tipo;
        switch(tipo) {
            case 1:
                cin >> ar >> x >> y;
                raiz[ar] = upd(raiz[ar], 1, n, x, y);
                break;
            case 2:
                cin >> ar >> x >> y;
                cout << query(raiz[ar], 1, n, x, y) << '\n';
                break;
            case 3:
                cin >> ar;
                raiz[lst++] = disp;
                esq[disp] = esq[raiz[ar]];
                dir[disp] = dir[raiz[ar]];
                a[disp] = a[esq[disp]] + a[dir[disp]];
                disp++;
                break;
        }
    }
    return 0;
}