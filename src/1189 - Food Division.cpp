/*
Problem Name: Food Divison
Problem Link: https://cses.fi/problemset/task/1189
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 5;
const ll INF = 2e18;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n), flow(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        a[i] = b[i] - a[i];
        if (i) flow[i] = flow[i - 1] + a[i - 1];
    }
    sort(flow.begin(), flow.end());
    int ans = flow[n / 2];
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        tot += abs(flow[i] - ans);
    }
    cout << tot << '\n';
    return 0;
}