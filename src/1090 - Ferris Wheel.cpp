/*
Problem Name: Ferris Wheel
Problem Link: https://cses.fi/problemset/task/1090
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 1000005
 
using namespace std;
typedef long long int lli;
 
pair<int, bool> p[MAXN];
 
int main () { _
    int n, x, resp = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
    }
    sort(p, p+n);
    int j = n-1;
    for (int i = 0; i < n && !p[i].second; i++) {
        while (p[i].first + p[j].first > x and !p[i].second) {
            resp++;
            p[j].second = true;
            j--;
        }
        if (!p[i].second and !p[j].second) {
            resp++;
            p[i].second = true;
            p[j].second = true;
            j--;
        }
    }
    cout << resp << endl;
    return 0;
}