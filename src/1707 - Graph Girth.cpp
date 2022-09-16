// Graph Girth
//
// Problem name: Graph Girth
// Problem Link: https://cses.fi/problemset/task/1707
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 2505
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
int dist[MAXN];
 
int main() { _
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	int ans = MAXN;
	for (int i = 1; i <= n; i++) {
		memset(dist, -1, sizeof(dist));
		dist[i] = 0;
		queue<int> fila;
		fila.push(i);
		int achei = MAXN, atual;
		while (!fila.empty() && dist[atual] <= achei) {
			atual = fila.front();
			fila.pop();
			for (int x : v[atual]) {
				if (dist[x] == -1) {
					dist[x] = dist[atual]+1;
					fila.push(x);
				}
				else if (dist[x] >= dist[atual]) {
					ans = min(ans, dist[x] + dist[atual] + 1);
					achei = dist[atual];
				}
			}
		}
	}
	cout << (ans==MAXN ? -1 : ans) << '\n';
	return 0;
}