/*
Problem Name: Chessboard and Queens
Problem Link: https://cses.fi/problemset/task/1624
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1000100
#define INF 1000005
 
using namespace std;
typedef long long int lli;
 
const int mod = 1e9 + 7;
const int n_q = 8;
 
bool m[n_q][n_q];
 
int queen(int n) {
    if (n == n_q) return 1;
    int resp = 0;
    bool aux[n_q][n_q];
    for (int i = 0; i < n_q; i++) {
        for (int j = 0; j < n_q; j++) {
            aux[i][j] = m[i][j];
        }
    }
    int i = n;
    for (int j = 0; j < n_q; j++) {
        if (m[i][j]) {
            for (int k = 0; k < n_q; k++) {
                m[i][k] = m[k][j] = false;
                for (int l = 0; l < n_q; l++) {
                    if ((i-j) == (k-l) or (i+j) == (k+l)) m[k][l] = false;
                }
            }
            resp += queen(n+1);
            for (int k = 0; k < n_q; k++) {
                for (int l = 0; l < n_q; l++) {
                    m[k][l] = aux[k][l];
                }
            }
        }
    }
    return resp;
}
 
int main () { _
    char c;
    for (int i = 0; i < n_q; i++) {
        for (int j = 0; j < n_q; j++) {
            cin >> c;
            if (c == '*') m[i][j] = false;
            else m[i][j] = true;
        }
    }
    cout << queen(0) << endl;
    return 0;
}