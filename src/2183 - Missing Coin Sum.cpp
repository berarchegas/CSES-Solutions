// Missing Coin Sum
//
// Problem name: Missing Coin Sum
// Problem Link: https://cses.fi/problemset/task/2183
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
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
	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	ll resp = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] - resp > 1) break;
		else resp += v[i];
	}
	cout << resp+1 << '\n';
	return 0;
}