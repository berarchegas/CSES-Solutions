// Sum of Divisors
//
// Problem name: Sum of Divisors
// Problem Link: https://cses.fi/problemset/task/1082
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

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
    ll n;
    cin >> n;
    ll ans = 0, last = n, ult, um, dois;
    for (int i = 2; i <= 1e6; i++) {
        ult = n/i + 1;
        if ((last + ult) % 2 == 0) {
            um = ((last + ult) / 2) % M;
            dois = (last - ult + 1) % M;
        }
        else {
            um = (last + ult) % M;
            dois = ((last - ult + 1) / 2) % M;
        }
        ll mais = (um * dois) % M;
        mais = (mais * (i-1)) % M;
        ans += mais;
        if (ans >= M) ans -= M;
        last = ult-1;
    }
    for (int i = 1; i <= last; i++) {
        ans = (ans + (n/i * i)) % M;
    }
    cout << ans << '\n';
    return 0;   
}