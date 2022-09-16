// Two Sets
//
// Problem name: Two Sets
// Problem Link: https://cses.fi/problemset/task/1092
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
 
using namespace std;
typedef long long int lli;
 
int main() { _
    int n;
    cin >> n;
    vector<int> v1, v2;
    if (n % 2 == 0) {
        if (n % 4 != 0) cout << "NO" << endl;
        else {
            for (int i = 1; i <= n/4; i++) {
                v1.push_back(i);
                v1.push_back(n-i+1);
            }
            for (int i = n/4 + 1; i <= n/2; i++) {
                v2.push_back(i);
                v2.push_back(n-i+1);
            }
            cout << "YES" << endl;
            cout << (int)v1.size() << endl;
            for (int i = 0; i < (int)v1.size(); i++) {
                cout << v1[i] << " ";
            }
            cout << endl << (int)v2.size() << endl;
            for (int i = 0; i < (int)v2.size(); i++) {
                cout << v2[i] << " ";
            }
            cout << endl;
        }
    }
    else {
        if ((n+1) % 4 != 0) cout << "NO" << endl;
        else {
            bool ber = true;
            for (int i = 1; i <= n; i++) {
                if (ber) v1.push_back(i);
                else v2.push_back(i);
                if (i%2 == 0) ber = 1 - ber;
            }
            cout << "YES" << endl;
            cout << (int)v1.size() << endl;
            for (int i = 0; i < (int)v1.size(); i++) {
                cout << v1[i] << " ";
            }
            cout << endl << (int)v2.size() << endl;
            for (int i = 0; i < (int)v2.size(); i++) {
                cout << v2[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}