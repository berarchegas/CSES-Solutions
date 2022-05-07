/*
Problem Name: Monotone Subsequences
Problem Link: https://cses.fi/problemset/task/2215
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
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (k < ceil(sqrt(n))) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            vector<int> ans(n);
            int a = ceil(sqrt(n));
            for (int i = k; i > 0; i--) cout << i << ' ';
            int temos = n - k, grupos = a - 1;
            if (grupos == 0) {
                cout << '\n';
                continue;
            }
            for (int i = 0; i < temos % grupos; i++) {
                for (int j = 0; j < temos / grupos + 1; j++) {
                    cout << k + (temos / grupos + 1) * (i + 1) - j << ' ';
                }
            }
            int lst = k + (temos / grupos + 1) * (temos % grupos);
            for (int i = 0; i < grupos - temos % grupos; i++) {
                for (int j = 0; j < temos / grupos; j++) {
                    cout << lst + (temos / grupos) * (i + 1) - j << ' ';
                }
            }
            cout << '\n';
        }
    }
    return 0;
}