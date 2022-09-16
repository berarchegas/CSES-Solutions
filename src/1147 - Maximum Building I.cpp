// Maximum Building I
//
// Problem name: Maximum Building I
// Problem Link: https://cses.fi/problemset/task/1147
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
const ll INF = 1e18;
 
char mat[1010][1010];
int maxi[1010][1010];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	memset(maxi, -1, sizeof(maxi));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
			maxi[i][j] = (mat[i][j] == '.');
			if (maxi[i][j] && i > 1) maxi[i][j] += maxi[i-1][j];
		}
	}
	//for (int i = n; i > 1; i--) {
	//	for (int j = 1; j <= m; j++) {
	//		if (maxi[i-1][j]) maxi[i-1][j] = max(maxi[i][j], maxi[i-1][j]);
	//	}
	//}
	ll ans = 0;
	vector<int> besq(m+1), bdir(m+1);
	for (int i = 1; i <= m; i++) {
		besq[i] = i-1;
		bdir[i] = i+1;
	}
	for (int i = 1; i <= n; i++) {
		vector<int> esq, dir;
		esq = besq, dir = bdir;
		for (int j = 1; j <= m; j++) {
			while (maxi[i][esq[j]] >= maxi[i][j]) {
				esq[j] = esq[esq[j]];
			}
		}
		for (int j = m; j >= 1; j--) {
			while (maxi[i][dir[j]] >= maxi[i][j]) {
				dir[j] = dir[dir[j]];
			}
		}
		for (int j = 1; j <= m; j++) {
			ans = max(ans, 1ll * (dir[j] - esq[j] - 1) * maxi[i][j]);
		}
	}
	cout << ans << '\n';
    return 0;
}