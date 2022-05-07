/*
Problem Name: Exponentiation
Problem Link: https://cses.fi/problemset/task/1095
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 10010
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
        if (e&1) {
            resp = (resp * b) % M;
        }
        e = e >> 1;
        b = (b * b) % M;
    }
    return resp;
}
 
int main () { _
    int n;
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        cout << fexp(a, b) << '\n';
    }
    return 0;
}