/*
Problem Name: Christmas Party
Problem Link: https://cses.fi/problemset/task/1717
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
 
int main () { _
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        ans = (ans * i + (i&1 ? - 1 : 1)) % M;
    }
    cout << ans << '\n';
    return 0;
}