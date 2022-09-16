// Increasing Subsequence
//
// Problem name: Increasing Subsequence
// Problem Link: https://cses.fi/problemset/task/1145
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
    int n;
    cin >> n;
    vector<int> v(n), pilha;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        auto it = lower_bound(pilha.begin(), pilha.end(), v[i]);
        if (it == pilha.end()) {
            pilha.pb(v[i]);
        }
        else *it = v[i];
    }
    cout << (int)pilha.size() << '\n';
    return 0;
}