/*
Problem Name: Tower of Hanoi
Problem Link: https://cses.fi/problemset/task/2165
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 100100
 
using namespace std;
typedef long long int lli;
 
void hanoi (int discos, int ini, int fim) {
    if (discos == 1) {
        cout << ini << " " << fim << endl;
    }
    else {
        int outro = 6-ini-fim;
        hanoi (discos-1, ini, outro);
        cout << ini << " " << fim << endl;
        hanoi (discos-1, outro, fim);
    }
}
 
int main() { _
    int n;
    cin >> n;
    cout << (int)(pow(2, n)-1) << endl;
    hanoi (n, 1, 3);
    return 0;
}