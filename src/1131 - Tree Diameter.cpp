// Tree Diameter
//
// Problem name: Tree Diameter
// Problem Link: https://cses.fi/problemset/task/1131
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

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
const int M = 1e9 + 7;
 
vector<int> v[MAXN];
int n;
 
int bfs(int node, bool flag) {
	queue<pii> q;
	vector<int> check(n+1);
	check[node] = 1;
	q.push({node, 0});
	int resp = 0, no;
	while (!q.empty()) {
		pii atual = q.front();
		q.pop();
		for (int x : v[atual.F]) {
			if (!check[x]) {
				check[x] = 1;
				q.push({x, atual.S+1});
				if (atual.S + 1 > resp) {
					resp = atual.S + 1;
					no = x;
				}
			}
		}
	}
	return (flag ? resp : no);
}
 
int main() { _
    int a, b;
	cin >> n;
	if (n == 1) cout << "0\n";
	else {
		for (int i = 0; i < n - 1; i++) {
			cin >> a >> b;
			v[a].pb(b);
			v[b].pb(a);
		}
		int no = bfs(1, false);
		cout << bfs(no, true) << '\n';
	}	
    return 0;
}