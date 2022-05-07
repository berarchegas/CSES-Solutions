/*
Problem Name: Number Spiral
Problem Link: https://cses.fi/problemset/task/1071
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
 
using namespace std;
typedef long long int lli;
 
int main() { _
    int t, x, y;
    lli resp;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> x >> y;
        if (x > y) {
            if (x%2==0) {
                resp = (1ll)*x*x - y + 1;
            }
            else {
                resp = (1ll)*(x-1)*(x-1) + y;
            }
        }
        else {
            if (y%2==0) {
                resp = (1ll)*(y-1)*(y-1) + x; 
            }
            else {
                resp = (1ll)*y*y - x + 1;
            }
        }
        cout << resp << endl;
    }
    return 0;
}