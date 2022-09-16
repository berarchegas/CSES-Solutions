// Two Knights
//
// Problem name: Two Knights
// Problem Link: https://cses.fi/problemset/task/1072
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
 
using namespace std;
typedef long long int lli;
 
int main() { _
    int n;
    lli resp;
    cin >> n;
    if (n >= 1) cout << "0" << endl;
    if (n >= 2) cout << "6" << endl;
    if (n >= 3) cout << "28" << endl;
    for (int i = 4; i <= n; i++) {
        resp = 0LL;
        resp += (1ll)*(i*i - 3)*4;
        resp += (1ll)*(i*i - 4)*8;
        resp += (1ll)*(i*i - 5)*(4 + 4*(i-4));
        resp += (1ll)*(i*i - 7)*(4*(i-4));
        resp += (1ll)*(i*i - 9)*(i-4)*(i-4);
        cout << resp/2 << endl;
    }
    return 0;
}