/*
Problem Name: Distributing Apples
Problem Link: https://cses.fi/problemset/task/1716
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
 
vector<int> fat(2, 1);
 
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
    ll f = 1;
    for (int i = 2; i < 3e6; i++) {
        f = (f*i) % M;
        fat.pb(f);
    }
    int n, m;
    cin >> n >> m;
    ll ans = ((ll)fat[n+m-1] * fexp(fat[n-1], M-2)) % M;
    ans = (ans * fexp(fat[m], M-2)) % M;
    cout << ans << '\n';
    return 0;
}