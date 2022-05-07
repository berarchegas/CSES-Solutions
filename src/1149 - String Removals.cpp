/*
Problem Name: String Removals
Problem Link: https://cses.fi/problemset/task/1149
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 5;
const ll INF = 1e18;
 
int dp[MAXN], last[MAXN];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(26, -1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        last[i] = (v[s[i-1]-'a'] < 0 ? -1 : v[s[i-1]-'a']);
        v[s[i-1] - 'a'] = i-1;
        dp[i] = dp[i-1] - (last[i] >= 0 ? dp[last[i]] : 0);
        if (dp[i] < 0) dp[i] += MOD;
        if (dp[i] >= MOD) dp[i] -= MOD;
        dp[i] += dp[i-1];
        if (dp[i] >= MOD) dp[i] -= MOD;
    }
    cout << (dp[n]-1+MOD) % MOD << '\n';
    return 0;
}