// Intersection Points
//
// Problem name: Intersection Points
// Problem Link: https://cses.fi/problemset/task/1740
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 2000100
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
 
struct line {
	int x1, x2, y1, y2, hor, take;
};
 
ll a[MAXN];
vector<line> l[MAXN];
 
void upd(int pos, int val) {for (; pos < MAXN; pos += (pos & -pos)) a[pos]+=val; }
 
ll sum(int pos) {
	ll ans = 0;
	for (; pos; pos -= (pos & -pos)) ans += a[pos];
	return ans;
}
 
int main () { _
	int n;
	cin >> n;
	line aux;
	for (int i = 0; i < n; i++) {
		cin >> aux.x1 >> aux.y1 >> aux.x2 >> aux.y2;
		aux.x1 += 1e6, aux.x2 += 1e6, aux.y1 += 1e6, aux.y2 += 1e6;
		aux.hor = (aux.y1 == aux.y2);
		aux.take = 1;
		l[aux.x1].pb(aux);
	}
	ll ans = 0;
	for (int i = 0; i <= 2e6; i++) {
		if (!l[i].empty()) {
			sort(l[i].begin(), l[i].end(), [&] (line a, line b) { return a.hor > b.hor; });
			for (line &x : l[i]) {
				if (x.hor) {
					upd(x.y1, x.take);
					if (x.take == 1) {
						x.take = -1;
						l[x.x2].pb(x);
					}
				}
				else ans += sum(x.y2) - sum(x.y1-1);
			}
		}
	}
	cout << ans << '\n';
    return 0;
}