/*
Problem Name: Empty String
Problem Link: https://cses.fi/problemset/task/1080
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
 
int add(int a, int b) {
    if (a + b >= MOD)
        return a + b - MOD;
    if (a + b < 0)
        return a + b + MOD;
    return a + b;
}
 
int dp[505][505], c[505][505];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = add(c[i-1][j], c[i-1][j-1]);
        }
    }
    for (int i = 0; i+1 <= n; i++) 
        dp[i+1][i] = 1;
 
    for (int i = n-1; i >= 0; i--) {
        for (int j = i+1; j < n; j+=2) {
            for (int k = i+1; k <= j; k+=2) {
                if (s[i] == s[k]) 
                    dp[i][j] = add(dp[i][j], (((1ll * dp[i+1][k-1] * dp[k+1][j]) % MOD) * c[(j-i+1)/2][(k-i+1)/2]) % MOD);            
            }
        }
    }
    cout << dp[0][n-1] << '\n';
    return 0;
}