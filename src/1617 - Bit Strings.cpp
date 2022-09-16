// Bit Strings
//
// Problem name: Bit Strings
// Problem Link: https://cses.fi/problemset/task/1617
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
 
using namespace std;
typedef long long int lli;
 
const int big = 1e9+7;
 
int main() { _
    int n, resp = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        resp *= 2;
        resp %= big;
    }
    cout << resp << endl;
    return 0;
}