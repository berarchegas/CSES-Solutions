/*
Problem Name: Creating Strings I
Problem Link: https://cses.fi/problemset/task/1622
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1000100
#define INF 1000005
 
using namespace std;
typedef long long int lli;
 
const int mod = 1e9 + 7;
const int n_q = 5;
 
int v[26], ans = 0;
string s, respostas[50000];
 
void permutations (string resp) {
    for (int i = 0; i < 26; i++) {
        if (v[i] > 0) {
            v[i]--;
            char nova = i+97;
            resp.push_back(nova);
            permutations(resp);
            v[i]++;
            resp.pop_back();
        }
    }
    if ((int)resp.size() == (int)s.size()) {
        respostas[ans] = resp;
        ans++;   
    }
    
}
 
int main () { _
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        v[s.at(i)-97]++;
    }
    string ini = "";
    permutations(ini);
    cout << ans << endl;
    for (int i = 0; i < ans; i++) {
        cout << respostas[i] << endl;
    }
    return 0;
}