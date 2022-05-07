/*
Problem Name: Distinct Numbers
Problem Link: https://cses.fi/problemset/task/1621
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
 
set<int> conjunto;
 
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        conjunto.insert(aux);
    }
    cout << conjunto.size() << endl;
    return 0;
}