/*
Problem Name: Counting Grids
Problem Link: https://cses.fi/problemset/task/2210
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
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
 
ll fexp(ll b, int e) {
    ll resp = 1;
    while(e) {
        if(e&1) resp = (resp * b) % M;
        b = (b*b) % M;
        e = (e>>1);
    }
    return resp;
}
 
int main () { _
    ll n;
    cin >> n;
    if (n == 1) cout << "2\n";
    else {
        ll total = (n*n);
        ll ans = fexp(2, total % (M-1));
        ans += 2*fexp(2, (total/4 + (n&1)) % (M-1));
        ans += fexp(2, (total/2 + (n&1)) % (M-1));
        cout << (ans * fexp(4, M-2)) % M << '\n';
    }
    return 0;
}