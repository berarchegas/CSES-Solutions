/*
Problem Name: Permutation Inversions
Problem Link: https://cses.fi/problemset/task/2229
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
const ll INF = 1e18;
 
int dp[126000], pre[126000];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    dp[0] = 1;
    pre[0] = pre[1] = 1;
    for (int i = 2; i <= n; i++) {
        int lim = (i * (i-1)) / 2;
        for (int j = 0; j <= lim; j++) {
            dp[j] = pre[j] - (j-i >= 0 ? pre[j-i] : 0);
            if (dp[j] < 0) dp[j] += MOD;
            if (dp[j] >= MOD) dp[j] -= MOD;
        }
        lim = (i * (i+1)) / 2;
        for (int j = 0; j <= lim; j++) {
            pre[j] = dp[j] + (!j ? 0 : pre[j-1]);
            if (pre[j] >= MOD) pre[j] -= MOD;
        }
    }
    cout << dp[k] << '\n';
    return 0;
}