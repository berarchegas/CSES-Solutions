// Chess Tournament
//
// Problem name: Chess Tournament
// Problem Link: https://cses.fi/problemset/task/1697
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

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
 
int v[MAXN];
 
int main () { _
	int n;
	cin >> n;
	priority_queue<pii> fila;
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		if (v[i]) fila.push({v[i], i});
		tot = (v[i]&1 ? 1-tot : tot);
	}
	if (tot&1) cout << "IMPOSSIBLE\n";
	else {
		pii a1, a2;
		bool ok = true;
		vector<pii> ans;
		while (!fila.empty()) {
			a1 = fila.top();
			fila.pop();
			vector<pii> falta;
			while (v[a1.S]) {
				if (fila.empty()) {
					ok = false;
					break;
				}
				a2 = fila.top();
				fila.pop();
				v[a1.S]--, v[a2.S]--;
				ans.pb({a1.S, a2.S});
				if (v[a2.S]) falta.pb({v[a2.S], a2.S});
			}
			for (pii x : falta) fila.push(x);
		}
		if (!ok) cout << "IMPOSSIBLE\n";
		else {
			cout << ans.size() << '\n';
			for (pii x : ans) cout << x.F << ' ' << x.S << '\n';
		}
	}
    return 0;
}