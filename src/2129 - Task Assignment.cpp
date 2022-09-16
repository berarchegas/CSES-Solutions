// Task Assignment
//
// Problem name: Task Assignment
// Problem Link: https://cses.fi/problemset/task/2129
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 1e4 + 5;
const ll INF = 2e18;
 
template<typename T = int> struct hungarian {
	int n;
	vector<vector<T>> a;
	vector<T> u, v;
	vector<int> p, way;
	T inf;
 
	hungarian(int n_) : n(n_), u(n+1), v(n+1), p(n+1), way(n+1) {
		a = vector<vector<T>>(n, vector<T>(n));
		inf = numeric_limits<T>::max();
	}
	pair<T, vector<int>> assignment() {
		for (int i = 1; i <= n; i++) {
			p[0] = i;
			int j0 = 0;
			vector<T> minv(n+1, inf);
			vector<int> used(n+1, 0);
			do {
				used[j0] = true;
				int i0 = p[j0], j1 = -1;
				T delta = inf;
				for (int j = 1; j <= n; j++) if (!used[j]) {
					T cur = a[i0-1][j-1] - u[i0] - v[j];
					if (cur < minv[j]) minv[j] = cur, way[j] = j0;
					if (minv[j] < delta) delta = minv[j], j1 = j;
				}
				for (int j = 0; j <= n; j++)
					if (used[j]) u[p[j]] += delta, v[j] -= delta;
					else minv[j] -= delta;
				j0 = j1;
			} while (p[j0] != 0);
			do {
				int j1 = way[j0];
				p[j0] = p[j1];
				j0 = j1;
			} while (j0);
		}
		vector<int> ans(n);
		for (int j = 1; j <= n; j++) ans[p[j]-1] = j-1;
		return make_pair(-v[0], ans);
	}
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    hungarian ber(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> ber.a[i][j];
    }
    pair<int, vector<int>> ans = ber.assignment();
    cout << ans.first << '\n';
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ' ' << ans.second[i] + 1 << '\n';
    }
    return 0;
}