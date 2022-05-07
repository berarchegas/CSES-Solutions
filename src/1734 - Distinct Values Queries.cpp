/*
Problem Name: Distinct Values Queries
Problem Link: https://cses.fi/problemset/task/1734
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 1e17
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 998244353;
const int X = 700;
 
struct que {
	int l, r, id, ans;
};
 
int a[MAXN], v[MAXN];
vector<que> qs;
vector<int> c, vals[MAXN];
 
void upd(int pos, int val) {
	for (int i = pos; i < MAXN; i += (i & -i)) 
		a[i] += val;
}
 
int sum(int pos) {
	int ans = 0;
	for (int i = pos; i > 0; i -= (i & -i))
		ans += a[i];
	return ans;
}
 
int main() { _
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		c.pb(v[i]);
	}
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	for (int i = 1; i <= n; i++) {
		v[i] = upper_bound(c.begin(), c.end(), v[i]) - c.begin();
		if (vals[v[i]].empty()) upd(i, 1);
		vals[v[i]].pb(i);
	}
	que aux;
	for (int i = 0; i < q; i++) {
		cin >> aux.l >> aux.r;
		aux.id = i;
		qs.pb(aux);
	}
	sort(qs.begin(), qs.end(), [&] (que x, que y) { return x.l < y.l; });
	int last = 1, np;
	for (int i = 0; i < q; i++) {
		while (qs[i].l > last) {
			upd(last, -1);
			np = upper_bound(vals[v[last]].begin(), vals[v[last]].end(), last) - vals[v[last]].begin();
			if (np < (int)vals[v[last]].size()) upd(vals[v[last]][np], 1);
			last++;
		}
		qs[i].ans = sum(qs[i].r);
	}
	sort(qs.begin(), qs.end(), [&] (que x, que y) { return x.id < y.id; });
	for (que x : qs) cout << x.ans << '\n';
    return 0;
}