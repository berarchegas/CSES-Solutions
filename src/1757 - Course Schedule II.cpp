/*
Problem Name: Course Schedule II
Problem Link: https://cses.fi/problemset/task/1757
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
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
 
vector<int> v[MAXN];
int deg[MAXN], ans1[MAXN], ans2[MAXN];
 
int main () { _
	int n, m;
	cin >> n >> m;
	set<int> s;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].pb(a);
		deg[a]++;
	}
	for (int i = 1; i <= n; i++) 
		if (!deg[i]) s.insert(i);
	int cnt = n;
	while (!s.empty()) {
		auto x = s.end();
		x--;
		int a = *x;
		s.erase(a);
		ans1[a] = cnt--;
		for (int x : v[a]) {
			deg[x]--;
			if (!deg[x]) s.insert(x);
		}
	}
	for (int i = 1; i <= n; i++) ans2[ans1[i]] = i;
	for (int i = 1; i <= n; i++) cout << ans2[i] << ' ';
	cout << '\n';
    return 0;
}