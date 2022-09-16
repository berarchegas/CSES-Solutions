// Reading Books
//
// Problem name: Reading Books
// Problem Link: https://cses.fi/problemset/task/1631
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 300100
#define INF 100000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9+7;
 
int main() { _
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll a1 = 0, a2 = 0, ma1, ma2;
    for (int i = n-1; i >= 0; i--) {
        if (a1 <= a2) {
            a1 += v[i];
            ma1 = v[i];
        }
        else {
            a2 += v[i];
            ma2 = v[i];
        }
    }
    if (a1 > a2) {
        if (a2 >= ma1) cout << a1 + a2 << '\n';
        else cout << 2*a1 << '\n';
    }
    else {
        if (a1 >= ma2) cout << a1 + a2 << '\n';
        else cout << 2*a2 << '\n';
    }
	return 0;
}
