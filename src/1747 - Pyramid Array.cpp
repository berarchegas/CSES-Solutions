/*
Problem Name: Pyramid Array
Problem Link: https://cses.fi/problemset/task/1747
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
const ll INF = 2e18;
 
int a[MAXN];
 
void add(int pos, int val) {
    for (; pos < MAXN; pos += (pos & -pos)) a[pos] += val;
}
 
int sum(int pos) {
    int ans = 0;
    for (; pos; pos -= (pos & -pos)) ans += a[pos];
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
        add(i + 1, 1);
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += min(sum(n) - sum(v[i].second), sum(v[i].second - 1));
        add(v[i].second, -1);
    }
    cout << ans << '\n';
    return 0;
}