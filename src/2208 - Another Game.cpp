// Another Game
//
// Problem name: Another Game
// Problem Link: https://cses.fi/problemset/task/2208
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
    while (t--) {
        int n, aux;
        cin >> n;
        bool ans = false;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            ans |= (aux&1);
        }
        cout << (ans ? "first\n" : "second\n");
    }
    return 0;
}