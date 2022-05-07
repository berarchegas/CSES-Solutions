/*
Problem Name: Gray Code
Problem Link: https://cses.fi/problemset/task/2205
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 100100
 
using namespace std;
typedef long long int lli;
 
vector <string> v(MAXN);
 
int main() { _
    int n, atual = 2, tam = 2;
    cin >> n;
    v[0] = '0';
    v[1] = '1';
    while (atual <= n) {
        for (int i = 0; i < tam; i++) {
            v[2*tam-i-1] = v[i];
            v[i].push_back('0');
            v[2*tam-i-1].push_back('1');
        }
        tam *= 2;
        atual++;
    }
    for (int i = 0; i < tam; i++) {
        cout << v[i] << endl;
    }
    return 0;
}