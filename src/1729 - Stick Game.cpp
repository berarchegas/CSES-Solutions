/*
Problem Name: Stick Game
Problem Link: https://cses.fi/problemset/task/1729
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
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
    int n, k;
    cin >> n >> k;
    vector<int> v(k), ans(n+1);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (i - v[j] >= 0 && !ans[i-v[j]]) {
                ans[i] = 1;
                break;
            }
        }        
        cout << (ans[i] ? 'W' : 'L');
    }
    cout << '\n';
    return 0;
}