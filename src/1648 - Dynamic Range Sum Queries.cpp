/*
Problem Name: Range Sum Queries II
Problem Link: https://cses.fi/problemset/task/1648
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
 
using namespace std;
typedef long long int lli;
 
int n, q, v[MAXN];
lli BIT[MAXN];
 
void atualiza (int id, int novo, int antigo) {
    while(id <= n) {
        BIT[id] += novo - antigo;
        id += (id&-id);
    }
}
 
lli soma (int id) {
    lli resp = 0;
    while (id > 0) {
        resp += BIT[id];
        id -= (id&-id);
    }
    return resp;
}
 
int main() { _
    int k, andar1, andar2, pessoas;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        atualiza(i, v[i], 0);
    }
    for (int i = 0; i < q; i++) {
        cin >> k;
        if (k==1){
            cin >> andar1 >> pessoas;
            atualiza(andar1, pessoas, v[andar1]);
            v[andar1] = pessoas;
        }
        else{
            cin >> andar1 >> andar2;
            cout << soma(andar2) - soma(andar1-1) << endl;
        }
    }
    return 0;
}