// Palindrome Reorder
//
// Problem name: Palindrome Reorder
// Problem Link: https://cses.fi/problemset/task/1755
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1000100
 
using namespace std;
typedef long long int lli;
 
const int big = 1e9+7;
 
int c[27], impar = 0, id_i;
 
int main() { _
    string s;
    vector<char> pa;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        c[s.at(i)-64]++;
    }
    for (int i = 1; i <= 26; i++) {
        if (c[i] % 2 != 0) {
            impar++;
            id_i = i;
        }
    }
    if (impar > 1) cout << "NO SOLUTION" << endl;
    else {
        for (int i = 1; i <= 26; i++) {
            for (int j = 0; j < c[i]/2; j++) {
                pa.push_back(i+64);
            }
        }
        for (int i = 0; i < (int)pa.size(); i++) {
            cout << pa[i];
        }
        if (impar == 1) cout << (char)(id_i+64);
        for (int i = (int)pa.size()-1; i >= 0; i--) {
            cout << pa[i];
        }
        cout << endl;
    }
    return 0;
}