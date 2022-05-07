/*
Problem Name: Grid Puzzle I
Problem Link: https://cses.fi/problemset/task/2432
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
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
    int n;
    cin >> n;
    priority_queue<pii> fila;
    pii aux;
    vector<int> linha(n);
    for (int i = 0; i < n; i++) {
        cin >> linha[i];
        aux.first = linha[i];
        aux.second = i;
        fila.push(aux);
    }
    vector<vector<char>> ans(n, vector<char> (n, '.'));
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        vector<pii> b;
        for (int j = 0; j < a; j++) {
            b.push_back(fila.top());
            fila.pop();
        } 
        for (auto x : b) {
            ans[x.second][i] = 'X';
            x.first--;
            fila.push(x);
        }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += ans[i][j] == 'X';
        }
        ok &= cnt == linha[i];
    }
    if (!ok) cout << "-1\n";
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}