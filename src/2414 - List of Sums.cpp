/*
Problem Name: List of Sums
Problem Link: https://cses.fi/problemset/task/2414
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
const ll INF = 2e18;
 
vector<int> v;
int n;
 
bool check(int a0) {
    multiset<int> st;
    for (int x : v) st.insert(x);
    vector<int> ans(1, a0);
    for (int i = 1; i < n; i++) {
        int bg = *st.begin();
        ans.push_back(bg - a0);
        st.erase(st.begin());
        for (int j = 1; j < (int)ans.size() - 1; j++) {
            if (st.find(ans.back() + ans[j]) == st.end())
                return false;
            else st.erase(st.find(ans.back() + ans[j]));
        }
    }
    for (int x : ans) cout << x << ' ';
    cout << '\n';
    return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int tam = n * (n - 1) / 2;
    v.resize(tam);
    for (int &x : v) cin >> x;
    sort(v.begin(), v.end());
    for (int i = 2; i < tam; i++) {
        // brute a1 + a2 = v[i]
        int a2 = (v[1] - v[0] + v[i]) / 2;
        int a1 = v[i] - a2, a0 = v[0] - a1;
        if (check(a0)) return 0;
    }
    return 0;
}