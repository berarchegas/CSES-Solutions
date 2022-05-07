/*
Problem Name: Candy Lottery
Problem Link: https://cses.fi/problemset/task/1727
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
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
const int M = 1e9 + 7;
 
int main () { _
	int n, x;
	cin >> n >> x;
	vector<vector<double>> dp(105, vector<double> (105));
	for (int i = 1; i <= x; i++) dp[n][i] = i;
	for (int i = n-1; i >= 0; i--) {
		for (int j = 1; j <= x; j++) {
			for (int k = 1; k <= x; k++) {
				dp[i][j] += 1.0 * dp[i+1][max(j, k)] / x;
			}
		}
	}
	cout << setprecision(6) << fixed;
	cout << dp[0][1] << '\n';
	return 0;
}