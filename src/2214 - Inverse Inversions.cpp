/*
Problem Name: Inverse Inversions
Problem Link: https://cses.fi/problemset/task/2214
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
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<int> v;
    int at = n-1;
    while (k) {
        if (k - at >= 0) {
            k -= at;
            v.push_back(at);
        }
        at--;
    }
    int baixo = 1, cima = n, id = 0;
    vector<int> perm(n);
    for (int i = n-1; i >= 0; i--) {
        if (id < (int)v.size() && i == v[id]) {
            perm[i] = baixo;
            baixo++;
            id++;
        }
        else {
            perm[i] = cima;
            cima--;
        }
    }
    for (int x : perm) cout << x << ' ';
    cout << '\n';
    return 0;
}