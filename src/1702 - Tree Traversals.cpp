/*
Problem Name: Tree Traversals
Problem Link: https://cses.fi/problemset/task/1702
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const ll INF = 1e18;
 
int pre[MAXN], in[MAXN], mapa[MAXN];
 
void build(int i1, int f1, int i2, int f2) {
    if (i1 > f1) return;
    int root = mapa[pre[i2]], tam = (root-i1);
    build(i1, root-1, i2+1, i2+tam);
    build(root+1, f1, i2+tam+1, f2);
    cout << in[root] << ' ';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        mapa[in[i]] = i;
    }
    build(0, n-1, 0, n-1);
    cout << '\n';
    return 0;
}