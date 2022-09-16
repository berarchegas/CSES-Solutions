// Longest Palindrome
//
// Problem name: Longest Palindrome
// Problem Link: https://cses.fi/problemset/task/1111
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 5;
const ll INF = 2e18;
 
int v[MAXN];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string ns, s;
    cin >> ns;
    s = "$";
    for (auto x : ns) s += "#", s += x;
    s += "#@";
    int c = 0, r = 0, n = s.size(), mx = 0;
    for (int i = 1; i < n - 1; i++) {
        int mir = 2 * c - i;
        if (i < r) {
            v[i] = min(v[mir], r - i);
        }
        while (s[i + v[i] + 1] == s[i - v[i] - 1]) v[i]++;
        if (i + v[i] > r) {
            c = i;
            r = i + v[i];
        }
        mx = max(mx, v[i]);
    }
    string ans;
    for (int i = 2; i < n - 1; i++) {
        if (v[i] == mx) {
            for (int j = (s[i - v[i]] == '#' ? i - v[i] + 1 : i - v[i]); j <= i + v[i]; j += 2) ans += s[j];
            cout << ans << '\n';
            break;
        }
    }
    return 0;
}