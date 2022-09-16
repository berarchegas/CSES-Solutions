// Minimal Rotation
//
// Problem name: Minimal Rotation
// Problem Link: https://cses.fi/problemset/task/1110
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const ll INF = 2e18;
 
// https://en.wikipedia.org/wiki/Lexicographically_minimal_string_rotation
 
int least_rotation(string s) {
    s += s;
    int n = s.size();
    vector<int> f(n, -1);
    int k = 0;
    for (int j = 1; j < n; j++) {
        int sj = s[j];
        int i = f[j - k - 1];
        while (i != -1 && sj != s[k + i + 1]) {
            if (sj < s[k + i + 1])
                k = j - i - 1;
            i = f[i];
        }
        if (sj != s[k + i + 1]) {
            if (sj < s[k])
                k = j;
            f[j - k] = -1;
        }
        else {
            f[j - k] = i + 1;
        }
    }
    return k;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int st = least_rotation(s), n = s.size();
    for (int i = st; i < n; i++) cout << s[i];
    for (int i = 0; i < st; i++) cout << s[i];
    cout << '\n';
    return 0;
}