// Area of Rectangles
//
// Problem name: Area of Rectangles
// Problem Link: https://cses.fi/problemset/task/1741
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
    
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 5;
const int INF = 2e9;
 
struct op {
    int x, y1, y2;
    bool open;
    op(int _x = 0, int _y1 = 0, int _y2 = 0, bool _open = false) {
        x = _x, y1 = _y1, y2 = _y2, open = _open;
    }
};
 
bool comp(op a, op b) {
    if (a.x != b.x) return a.x < b.x;
    return a.open > b.open;
}
 
struct no {
    int mn, qtd, lz;
    no(int _mn = 0, int _qtd = 0, int _lz = 0) {
        mn = _mn, qtd = _qtd, lz = _lz;
    }
    no operator + (const no &x) const {
        no aux;
        if (mn < x.mn) {
            aux.mn = mn;
            aux.qtd = qtd;
        }
        else if (mn == x.mn) {
            aux.mn = mn;
            aux.qtd = qtd + x.qtd;
        }
        else {
            aux.mn = x.mn;
            aux.qtd = x.qtd;
        }
        aux.lz = lz;
        return aux;
    }
}a[4 * MAXN];
 
void build(int node, int i, int j) {
    if (i == j) {
        a[node] = no(0, 1, 0);
    }
    else {
        int m = (i + j) / 2;
        build(2 * node, i, m), build(2 * node + 1, m + 1, j);
        a[node] = a[2 * node] + a[2 * node + 1];
    }
}
 
void push(int node, int i, int j) {
    if (a[node].lz) {
        a[node].mn += a[node].lz;
        if (i != j) {
            a[2 * node].lz += a[node].lz;
            a[2 * node + 1].lz += a[node].lz;
        }
        a[node].lz = 0;
    }
}
 
void update(int node, int i, int j, int ini, int fim, int val) {
    push(node, i, j);
    if (j < ini || i > fim) return;
    else if (ini <= i && j <= fim) {
        a[node].lz += val;
        push(node, i, j);
    }
    else {
        int m = (i + j) / 2;
        update(2 * node, i, m, ini, fim, val);
        update(2 * node + 1, m + 1, j, ini, fim, val);
        a[node] = a[2 * node] + a[2 * node + 1];
    }
}
 
ll query(int node, int i, int j) {
    push(node, i, j);
    return a[1].qtd;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, c, d;
    cin >> n;
    build(1, 0, 2000000);
    vector<op> v(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        b += 1000000, d += 1000000 - 1;
        v[2 * i] = op(a, b, d, true), v[2 * i + 1] = op(c, b, d, false);
    }
    sort(v.begin(), v.end(), comp);
    int lst = -1000000;
    ll ans = (2000001ll) * (2000001ll);
    for (auto o : v) {
        if (o.x != lst) {
            // novo x
            ans -= query(1, 0, 2000000) * (o.x - lst);
            lst = o.x;
        }
        if (o.open) {
            // comeco de intervalo
            update(1, 0, 2000000, o.y1, o.y2, 1);
        }
        else {
            // fim de intervalo
            update(1, 0, 2000000, o.y1, o.y2, -1);
        }
    }
    cout << ans - query(1, 0, 2000000) * (1000000 - lst + 1) << '\n';
    return 0;
}