// Inversion Probability
//
// Problem name: Inversion Probability
// Problem Link: https://cses.fi/problemset/task/1728
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
const int M = 1e9 + 7;
 
int main () { _
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	vector<vector<double>> dp(105, vector<double> (105));
	vector<double> prob(105);
	for (int i = 1; i < v[0]; i++) {
		prob[i] += ((double)v[0] - i) / v[0];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= v[i]; j++) {
			dp[i][j] = prob[j];
			for (int k = 1; k <= v[i-1]; k++) {
				dp[i][j] += (dp[i-1][k]) / v[i-1];
			}
		}
		for (int j = 1; j < v[i]; j++) {
			prob[j] += ((double)v[i] - j) / v[i];
		}
	}
	double ans = 0;
	for (int i = 1; i <= v[n-1]; i++) ans += dp[n-1][i];
	cout << setprecision(6) << fixed;
	cout << ans / v[n-1] << '\n';
	return 0;
}