// Trailing Zeros
//
// Problem name: Trailing Zeros
// Problem Link: https://cses.fi/problemset/task/1618
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
 
using namespace std;
typedef long long int lli;
 
const int big = 1e9+7;
 
int main() { _
    int n, resp = 0, div = 5;
    cin >> n;
    while (div <= n) {
        resp += n/div;
        div *= 5;
    }
    cout << resp << endl;
    return 0;
}