/*
Problem Name: Counting Necklaces
Problem Link: https://cses.fi/problemset/task/2209
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
    while(e) {
        if(e&1) resp = (resp * b) % M;
        b = (b*b) % M;
        e = (e>>1);
    }
    return resp;
}
 
int main () { _
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += fexp(m, __gcd(i, n));
        if (ans >= M) ans -= M;
    }
    cout << (ans * fexp(n, M-2)) % M << '\n';
    return 0;
}