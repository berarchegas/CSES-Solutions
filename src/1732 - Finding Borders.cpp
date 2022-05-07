/*
Problem Name: Finding Borders
Problem Link: https://cses.fi/problemset/task/1732
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1000100
#define INF 1e18
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 1e9+7;
 
int pre[MAXN], pwr[MAXN];
 
int main () { _
	string s1;
	cin >> s1;
	int tam1 = (int)s1.size();
	pwr[0] = 1;
	for (int i = 1; i <= 1e6; i++) pwr[i] = (1ll * pwr[i-1] * 31) % M;
	for (int i = 0; i < tam1; i++) {
		pre[i] = ((!i ? 0 : pre[i-1]) + (s1[i] - 'a' + 1ll) * pwr[i]) % M;
	}
	vector<int> ans;
	for (int i = 0; i < tam1-1; i++) {
		if ((1ll * pre[i] * pwr[tam1-i-1]) % M == (pre[tam1-1] - pre[tam1-i-2] + M) % M)
			ans.pb(i+1);
	}
	for (int x : ans) cout << x << '\n';
    return 0;
}