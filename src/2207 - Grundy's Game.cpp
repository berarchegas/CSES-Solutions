// Grundy's Game
//
// Problem name: Grundy's Game
// Problem Link: https://cses.fi/problemset/task/2207
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1000100
#define INF 100000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9+7;
 
int main () { _
    int t;
    cin >> t;
    vector<int> v(2050);
    for (int i = 3; i <= 2000; i++) {
        vector<int> aux;
        for (int j = i-1; j > i-j; j--) {
           aux.pb(v[j] ^ v[i-j]);
        }
        sort(aux.begin(), aux.end());
        int resp = 0;
        for (auto x : aux) {
            if (x > resp) break;
            else if (x == resp) resp++;
        }
        v[i] = resp;
    }
    while (t--) {
        int n;
        cin >> n;
        if (n <= 2000) {
            cout << (v[n] ? "first\n" : "second\n");
        }
        else cout << "first\n";
    }
    return 0;
}