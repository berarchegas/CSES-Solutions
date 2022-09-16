// Factory Machines
//
// Problem name: Factory Machines
// Problem Link: https://cses.fi/problemset/task/1620
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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ll l = 0, r = 1e18+1;
    while (r > l + 1) {
        ll m = (l+r)>>1, count = 0;
        for (int i = 0; i < n && count < k; i++) count += m/v[i];
        if (count >= k) r = m;
        else l = m;
    }
    cout << r << '\n';
	return 0;
}