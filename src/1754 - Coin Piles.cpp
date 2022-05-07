/*
Problem Name: Coin Piles
Problem Link: https://cses.fi/problemset/task/1754
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
 
using namespace std;
typedef long long int lli;
 
const int big = 1e9+7;
 
int main() { _
    int t, a, b;
    bool ber;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ber = true;
        cin >> a >> b;
        int mod1 = a%3;
        int mod2 = b%3;
        if (a > 2*b or b > 2*a) ber = false;
        if ((mod1 == 0 and mod2 != 0) or (mod2 == 0 and mod1 != 0)) ber = false;
        if ((mod1 == 1 and mod2 != 2) or (mod2 == 1 and mod1 != 2)) ber = false;
        if ((mod1 == 2 and mod2 != 1) or (mod2 == 2 and mod1 != 1)) ber = false;
        if (ber) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}