/*
Problem Name: Company Queries I
Problem Link: https://cses.fi/problemset/task/1687
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 1000000001
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9+7;
 
int tab[MAXN][25];
vector<int> v[MAXN];
 
void dfs(int node) {
	for (int i = 1; i < 20; i++) {
		tab[node][i] = tab[tab[node][i-1]][i-1];
	}
	for (int x : v[node]) {
		dfs(x);
	}
}
 
int main () { _
	memset(tab, 0, sizeof(tab));
	int n, q;
	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		cin >> tab[i][0];
		v[tab[i][0]].pb(i);
	}
	dfs(1);
	for (int i = 0; i < q; i++) {
		int x, k;
		cin >> x >> k;
		for (int j = 0; j < 20; j++) {
			if (k & (1<<j)) x = tab[x][j];
		}
		cout << (!x ? -1 : x) << '\n';
	}
	return 0;	
}