/*
Problem Name: Counting Divisors
Problem Link: https://cses.fi/problemset/task/1713
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
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
    int t;
    cin >> t;
    vector<int> div(MAXN, 1);
    for (int i = 2; i < 1e6+1; i++) {
        for (int j = i; j < 1e6+1; j+=i) div[j]++;
    }
    while (t--) {
        int n;
        cin >> n;
        cout << div[n] << '\n';
    }    
    return 0;
}