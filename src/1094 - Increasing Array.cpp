/*
Problem Name: Increasing Array
Problem Link: https://cses.fi/problemset/task/1094
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
 
using namespace std;
typedef long long int lli;
 
int main() { _
    int n, v[MAXN], atual = 0;
    cin >> n;
    lli resp = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] >= atual) atual = v[i];
        else resp += atual - v[i];
    }
    cout << resp << endl;
    return 0;
}