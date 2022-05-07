/*
Problem Name: Programmers and Artists
Problem Link: https://cses.fi/problemset/task/2426
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
const ll INF = 2e18;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p, a, n;
    cin >> p >> a >> n;
    vector<pii> v(n);
    for (auto &x : v) cin >> x.first >> x.second;
    sort(v.rbegin(), v.rend());
    if (!p) {
        priority_queue<int> fila;
        for (auto x : v) fila.push(x.second);
        ll ans = 0;
        for (int i = 0; i < a; i++) {
            ans += fila.top();
            fila.pop();
        }
        cout << ans << '\n';
        return 0;
    }
    vector<ll> pre(n + 1), suf(n + 1);
    
    // pegar 0 dos p primeiros, 1 dos p + 1...
    priority_queue<ll> fila;
    ll tot = 0;
    for (int i = 0; i < p; i++) {
        tot += v[i].first;
        fila.push(v[i].second - v[i].first);
        pre[i] = tot;
    } 
    for (int i = p; i < p + a; i++) {
        ll mx = fila.top();
        fila.pop();
        tot += mx + v[i].first;
        pre[i] = tot;
        fila.push(v[i].second - v[i].first);
    }
 
    while (!fila.empty()) fila.pop();
    for (int i = n - 1; i >= p + a; i--) {
        fila.push(v[i].second);
    }
    tot = 0;
    for (int i = p + a - 1; i >= p; i--) {
        fila.push(v[i].second);
        ll mx = fila.top();
        fila.pop();
        tot += mx;
        suf[i] = tot;
    }
    ll ans = 0;
    for (int i = max(0, p - 1); i < p + a; i++) {
        ans = max(ans, pre[i] + suf[i + 1]);
    }
    cout << ans << '\n';
    return 0;
}