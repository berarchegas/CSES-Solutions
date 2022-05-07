/*
Problem Name: Sum of Two Values
Problem Link: https://cses.fi/problemset/task/1640
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]] = i + 1;
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (mp[x - v[i]] && mp[x - v[i]] != (i + 1)) {
            cout << i + 1 << ' ' << mp[x - v[i]] << endl;
            ok = true;
            break;
        }
    }
    if (!ok) cout << "IMPOSSIBLE" << endl;
    return 0;
}