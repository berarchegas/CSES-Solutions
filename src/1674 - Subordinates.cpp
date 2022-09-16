// Subordinates
//
// Problem name: Subordinates
// Problem Link: https://cses.fi/problemset/task/1674
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
 
vector<int> v[MAXN], dp(MAXN);
 
void dfs(int node) {
	for (int x : v[node]) {
		dfs(x);
		dp[node] += 1+dp[x];
	}
}
 
int main() { _
    int n, aux;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> aux;
		v[aux].pb(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
	cout << '\n';
    return 0;
}