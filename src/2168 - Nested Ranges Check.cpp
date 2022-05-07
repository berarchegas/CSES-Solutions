/*
Problem Name: Nested Ranges Check
Problem Link: https://cses.fi/problemset/task/2168
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 1000000001
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
 
int main () { _
    int n;
    cin >> n;
    vector<pair<pii, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].F.F >> v[i].F.S;
        v[i].S = i;
    }
    sort(begin(v), end(v), [&](pair<pii, int> a, pair<pii, int> b) {
        if (a.F.F == b.F.F) return a.F.S > b.F.S;
        return a.F.F < b.F.F;
    });
    int mini = 1e9+1;
    vector<pii> contem(n), contido(n);
    for (int i = n-1; i >= 0; i--) {
        contem[i].S = (v[i].F.S >= mini);
        contem[i].F = v[i].S;
        mini = min(mini, v[i].F.S);
    }
    int maxi = -1;
    for (int i = 0; i < n; i++) {
        contido[i].S = (v[i].F.S <= maxi);
        contido[i].F = v[i].S;
        maxi = max(maxi, v[i].F.S);
    }
    sort(begin(contem), end(contem));
    sort(begin(contido), end(contido));
    for (pii x : contem) cout << x.S << ' ';
    cout << '\n';
    for (pii x : contido) cout << x.S << ' ';
    cout << '\n';
	return 0;	
}