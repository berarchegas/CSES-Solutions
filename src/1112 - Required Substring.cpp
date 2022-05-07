/*
Problem Name: Required Substring
Problem Link: https://cses.fi/problemset/task/1112
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const ll INF = 2e18;
 
vector<int> prefix(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
 
vector<vector<int>> aut;
 
void automato(string s) {
    vector<int> kmp = prefix(s + '$');
    int n = s.size() + 1;
    aut.assign(n, vector<int> (26));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (i > 0 && 'A' + j != s[i]) 
                aut[i][j] = aut[kmp[i -  1]][j];
            else 
                aut[i][j] = i + ('A' + j == s[i]);
        }
    }
}
 
void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
 
// dp[position][size of prefix of s][char i´m at]
int dp[1005][105];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string s;
    cin >> n >> s;
    m = s.size();
    automato(s);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 26; k++) {
                if (aut[j][k] == m) continue;
                add(dp[i + 1][aut[j][k]], dp[i][j]);
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++) ans = (ans * 26ll) % MOD;
    for (int i = 0; i < m; i++) {
        add(ans, MOD - dp[n][i]);
    }
    cout << ans << '\n';
    return 0;
}