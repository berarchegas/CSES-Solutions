// Binary Subsequences
//
// Problem name: Binary Subsequences
// Problem Link: https://cses.fi/problemset/task/2430
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 5;
const ll INF = 1e18;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int mn = n + 1, ans = -1;
    for (int i = 0; i <= n / 2; i++) {
        // try i and n - i
        int cnt = 0;
        int a = i, b = n - i;
        bool ok = true;
        while (a || b) {
            if (a < b) swap(a, b);
            if (a == b) {
                ok = false;
                break;
            }
            cnt += a / (b + 1);
            a %= (b + 1);
        }
        if (ok && cnt < mn) {
            mn = cnt;
            ans = i;
        } 
    }
    string s;
    int a = ans, b = n - a, z = 0;
    while (a || b) {
        if (a < b) {
            swap(a, b);
            z ^= 1;
        }
        int tot = a / (b + 1);
        for (int i = 0; i < tot; i++) s += '0' + z;
        a %= (b + 1);
    }
    cout << s << '\n';
    return 0;
}