/*
Problem Name: Maximum Subarray Sum
Problem Link: https://cses.fi/problemset/task/1643
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1e5+2
#define INF 1000000001
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 998244353;
 
int main () { _
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	ll ans = -1e9 - 10, sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		ans = max(ans, sum);
		if (sum < 0) sum = 0;
	}
	cout << ans << '\n';
	return 0;
}