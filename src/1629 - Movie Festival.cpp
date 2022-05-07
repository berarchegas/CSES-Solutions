/*
Problem Name: Movie Festival
Problem Link: https://cses.fi/problemset/task/1629
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
	vector<pii> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].S >> v[i].F;
	sort(v.begin(), v.end());
	int ans = 0, cd = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].S >= cd) {
			ans++;
			cd = v[i].F;
		}
	}
	cout << ans << '\n';
	return 0;
}