/*
Problem Name: Creating Strings II
Problem Link: https://cses.fi/problemset/task/1715
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1000100
#define INF 100000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9+7;
 
int fexp(ll b, int e) {
    ll resp = 1;
    while (e) {
        if (e&1) resp = (resp * b) % M;
        e >>= 1;
        b = (b * b) % M;
    }
    return resp;
}
 
int main () { _
    string s;
    cin >> s;
    vector<int> v(30), fat(1e6+10);
    int n = (int)s.size();
    for (int i = 0; i < n; i++) {
        v[s[i] - 'a']++;
    }
    ll ans = 1;
    fat[0] = fat[1] = 1;
    for (int i = 2; i <= n; i++) {
        ans = (ans * i) % M;
        fat[i] = ans;
    }
    for (int i = 0; i < 30; i++) {
        ans = (ans * fexp(fat[v[i]], M-2)) % M;
    }
    cout << ans << '\n';
    return 0;   
}