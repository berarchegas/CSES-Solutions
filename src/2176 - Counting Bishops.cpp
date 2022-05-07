/*
Problem Name: Counting Bishops
Problem Link: https://cses.fi/problemset/task/2176
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
const ll INF = 1e18;
 
int dp[1005][250010], n, k;
 
int count(int diag) {
    if (diag&1) return diag / 4 * 2 + 1;
    return (diag-1) / 4 * 2 + 2;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    if (k > 2*n-1) cout << "0\n";
    else {
        dp[0][0] = dp[1][0] = 1;
        dp[1][1] = 1;
        for (int i = 0; i < 2*n-2; i++) {
            for (int j = 0; j <= k; j++) {
                if (dp[i][j]) {
                    dp[i+2][j] += dp[i][j];
                    if (dp[i+2][j] >= MOD) dp[i+2][j] -= MOD;
                    if (count(i+2) - j > 0) {
                        dp[i+2][j+1] += (1ll * dp[i][j] * (count(i+2) - j)) % MOD;
                        if (dp[i+2][j+1] >= MOD) dp[i+2][j+1] -= MOD;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= k; i++) {
            ans += (1ll * dp[2*n-1][i] * dp[2*n-2][k-i]) % MOD;
            if (ans >= MOD) ans -= MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}