/*
Problem Name: Apple Division
Problem Link: https://cses.fi/problemset/task/1623
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 100100
 
using namespace std;
typedef long long int lli;
 
int n, aux;
lli soma = 0;
vector <int> v;
 
lli dp(lli atual, int id) {
    if (id == n) return abs(soma - 2*atual);
    if ((atual + v[id])*2 <= soma) {
        return min (dp(atual + v[id], id+1), dp (atual, id+1));
    }
    return dp (atual, id+1);
}
 
bool ordem (int a, int b) { return a < b; }
 
int main() { _
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        soma += aux;
        v.push_back(aux);
    }
    sort(v.begin(), v.end(), ordem);
    lli resp = dp(0, 0);
    cout << resp << endl;
    return 0;
}