// Knuth Division
//
// Problem name: Knuth Division
// Problem Link: https://cses.fi/problemset/task/2088
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 100000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 998244353;
 
int v[5050], pos[5050][5050];
ll dp[5050][5050], pre[5050];
 
int main () { _
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		pre[i] = pre[i-1] + v[i];
		pos[i][i] = i;
	}
	for (int tam = 1; tam < n; tam++) {
		for (int i = 1; i+tam <= n; i++) {
			int j = i+tam;
			dp[i][j] = dp[i][pos[i][j-1]] + dp[pos[i][j-1]+1][j] + pre[j] - pre[i-1];
			pos[i][j] = pos[i][j-1];
			for (int k = pos[i][j]+1; k <= pos[i+1][j]; k++) {
				if (dp[i][k] + dp[k+1][j] + pre[j] - pre[i-1] < dp[i][j]) {
					dp[i][j] = dp[i][k] + dp[k+1][j] + pre[j] - pre[i-1];
					pos[i][j] = k;
				}
			}
		} 
	}
	cout << dp[1][n] << '\n';
    return 0;
}