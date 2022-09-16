// Prime Multiples
//
// Problem name: Prime Multiples
// Problem Link: https://cses.fi/problemset/task/2185
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
    ll n;
	int k;
	cin >> n >> k;
	vector<ll> v(k), l(k);
	for (int i = 0; i < k; i++) cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < k; i++) l[i] = n/v[i] + 1;
	ll ans = 0;
	for (int i = 1; i < (1<<k); i++) {
		ll tot = 1;
		bool par = true;
		for (int j = 0; j < k; j++) {
			if (i & (1<<j)) {
				par = 1-par;
				if (tot > l[j]) {
					tot = 0;
					break;	
				}
				tot *= v[j];
			}
		}
		if (tot) tot = n/tot;
		ans += (par ? -tot : tot);
	}
	cout << ans << '\n';
    return 0;   
}