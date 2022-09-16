// Maximum Subarray Sum II
//
// Problem name: Maximum Subarray Sum II
// Problem Link: https://cses.fi/problemset/task/1644
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

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
 
multiset<ll> s;
 
int main () { _
	int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
    }
    ll ans = -1e16;
    for (int i = 0; i <= n; i++) {
        if (i-a >= 0) s.insert(v[i-a]);
        if (i >= a) ans = max(ans, v[i] - *s.begin());
        if (i-b >= 0) s.erase(s.find(v[i-b]));
    }
    cout << ans << '\n';
	return 0;	
}