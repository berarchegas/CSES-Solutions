/*
Problem Name: Permutations II
Problem Link: https://cses.fi/problemset/task/1075
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 4e5 + 5;
const ll INF = 2e18;
 
int dp[1005][1005][2];
 
void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
 
int mul(int a, int b) {
    return (1ll * a * b) % MOD;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    dp[1][0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            add(dp[i + 1][j + 1][1], mul(2, dp[i][j][0]));
            if (j)
                add(dp[i + 1][j - 1][0], mul(j, dp[i][j][0]));
            add(dp[i + 1][j][0], mul(i - j - 1, dp[i][j][0]));
            add(dp[i + 1][j + 1][1], dp[i][j][1]);
            if (j)
                add(dp[i + 1][j - 1][0], mul(j - 1, dp[i][j][1]));
            add(dp[i + 1][j][0], mul(i - j, dp[i][j][1]));
            add(dp[i + 1][j][1], dp[i][j][1]);
        }
    }
    cout << dp[n][0][0] << '\n';
    return 0;
}