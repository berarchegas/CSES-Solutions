/*
Problem Name: String Reorder
Problem Link: https://cses.fi/problemset/task/1743
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
 
vector<int> v(26);
string s;
 
bool valid(int n) {
    int maxi = 0;
    for (int i = 0; i < 26; i++) maxi = max(maxi, v[i]);
    if (maxi > n - maxi + 1) return false;
    return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int maxi = 0, n = s.size();
    for (auto x : s) {
        v[x-'A']++;
        maxi = max(maxi, v[x-'A']);
    }
    if (maxi > n - maxi + 1) cout << "-1\n";
    else {
        string ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (v[j] && (!i ? true : (ans[i-1] != (('A' + j))))) {
                    v[j]--;
                    ans += ('A'+j);
                    if (valid(n - i - 1)) break;
                    else {
                        v[j]++;
                        ans.pop_back();
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}