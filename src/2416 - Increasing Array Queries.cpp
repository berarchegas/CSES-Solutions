/*
Problem Name: Increasing Array Queries
Problem Link: https://cses.fi/problemset/task/2416
Author: Bernardo Archegas (codeforces/profile/Ber)
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
const int M = 998244353;
 
struct que{
	int l, r, id;
};
 
ll v[MAXN], a[MAXN], pre[MAXN], cb[MAXN], resp[MAXN];
vector<que> qs[MAXN];
 
void upd(int pos, ll val) { for (int i = pos; i < MAXN; i += (i & -i)) a[i] += val; }
 
ll sum(int pos) {
	ll ans = 0;
	for (int i = pos; i > 0; i -= (i & -i)) ans += a[i];
	return ans;
}
 
int main () { _
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		pre[i] = v[i] + pre[i-1];
	}
	v[n+1] = INF;
	pre[n+1] = v[n+1] + pre[n];
	que aux;
	for (int i = 0; i < q; i++) {
		cin >> aux.l >> aux.r;
		aux.id = i;
		qs[aux.l].pb(aux);
	}
	deque<int> sk(1, n+1);
	for (int i = n; i > 0; i--) {
		while (v[i] > v[sk.front()]) {
			upd(sk.front(), -cb[sk.front()]);
			sk.pop_front();
		}
		cb[i] = 1ll * (sk.front() - i - 1) * v[i] - (pre[sk.front() - 1] - pre[i]);
		upd(i, cb[i]);
		sk.push_front(i);
		for (que x : qs[i]) {
			int pos = upper_bound(sk.begin(), sk.end(), x.r) - sk.begin() - 1;
			ll ans = sum(sk[pos]) - 1ll * (sk[pos+1] - x.r - 1) * v[sk[pos]] + (pre[sk[pos+1]-1] - pre[x.r]); 
			resp[x.id] = ans;
		}
	}
	for (int i = 0; i < q; i++) cout << resp[i] << '\n';
    return 0;
}