/*
Problem Name: Repeating Substring
Problem Link: https://cses.fi/problemset/task/2106
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
 
void count_sort(vector<int> &p, vector<int> &c) {
    int n = p.size();
    vector<int> cnt(n);
    for (auto x : c) cnt[x]++;
    vector<int> p_new(n), pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (auto x : p) {
        p_new[pos[c[x]]] = x;
        pos[c[x]]++;
    }
    p = p_new;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    s += '$';
    int n = s.size();
    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++) a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i - 1].first == a[i].first) c[p[i]] = c[p[i - 1]];
            else c[p[i]] = c[p[i - 1]] + 1;
        }
    }
    int k = 0;
    while ((1 << k) < n) {
        for (int i = 0; i < n; i++) p[i] = (p[i] - (1 << k) + n) % n;
        count_sort(p, c);
        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            pii prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            pii now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            if (prev == now) c_new[p[i]] = c_new[p[i - 1]];
            else c_new[p[i]] = c_new[p[i - 1]] + 1;
        }
        c = c_new;
        k++;
    }
    vector<int> lcp(n);
    k = 0;
    for (int i = 0; i < n - 1; i++) {
        int pi = c[i];
        int j = p[pi - 1];
        while (s[i + k] == s[j + k]) k++;
        lcp[pi] = k;
        k = max(k - 1, 0);
    }
    int max = 0, id = -1;
    for (int i = 0; i < n; i++) {
        if (lcp[i] > max) {
            max = lcp[i];
            id = p[i];
        }
    }
    if (!max) cout << "-1\n";
    else {
        for (int i = id; i < id + max; i++) cout << s[i];
        cout << '\n';
    }
    return 0;
}