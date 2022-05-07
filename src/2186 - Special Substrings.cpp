/*
Problem Name: Special Substrings
Problem Link: https://cses.fi/problemset/task/2186
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
 
map<vector<int>, int> mp;
map<char, int> mapao;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    set<char> st;
    for (auto x : s) st.insert(x);
    int tam = st.size();
    vector<int> v(tam);
    mp[v] = 1;
    ll ans = 0;
    int cnt = 0;
    for (auto x : st) {
        mapao[x] = cnt;
        cnt++;
    }
    for (int i = 0; i < n; i++) {
        v[mapao[s[i]]]++;
        vector<int> nv = v;
        int mn = *min_element(v.begin(), v.end());
        for (int j = 0; j < tam; j++) nv[j] -= mn;
        ans += mp[nv];
        mp[nv]++;
    }
    cout << ans << '\n';
    return 0;
}