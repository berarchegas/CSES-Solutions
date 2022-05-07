/*
Problem Name: Binomial Coefficients
Problem Link: https://cses.fi/problemset/task/1079
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
    vector<int> fat(1e6+10), inv(1e6+10);
    fat[0] = fat[1] = 1;
    for (int i = 2; i <= 1e6; i++) {
        fat[i] = ((ll) fat[i-1] * i) % M;
    }
    inv[1e6] = fexp(fat[1e6], M-2);
    for (int i = 1e6-1; i >= 0; i--) {
        inv[i] = ((ll) inv[i+1] * (i+1)) % M;
    }
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << (((ll) fat[a] * inv[b]) % M * inv[a-b]) % M << '\n';
    }
    return 0;   
}