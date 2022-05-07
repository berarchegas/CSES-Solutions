/*
Problem Name: Xor Pyramid
Problem Link: https://cses.fi/problemset/task/2419
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 2000100
#define INF 1000000001
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 998244353;
 
int main () { _
	int n;
	cin >> n;
	vector<int> v(n), par(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	// par[i] = 1 if i submask de n
	for (int i = 0; i < n; i++) {
		par[i] = ((i & (n-1)) == i);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans ^= par[i] * v[i];
	}
	cout << ans << '\n';
	return 0;	
}