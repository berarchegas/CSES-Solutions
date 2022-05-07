/*
Problem Name: Dice Probability
Problem Link: https://cses.fi/problemset/task/1725
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 100100
#define INF 1000000001
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
 
int main () { _
	int n, a, b;
	cin >> n >> a >> b;
	vector<double> dp(605), ini(7);
	dp[0] = 1;
	for (int i = 1; i <= 6; i++) ini[i] = 1.0 / 6;
	for (int i = 0; i < n; i++) {
		for (int j = 600; j >= 0; j--) {
			dp[j] = 0;
			for (int k = j-1; k >= max(0, j-6); k--) {
				dp[j] += ini[j-k] * dp[k];
			}
		}
	}
	double ans = 0;
	for (int i = a; i <= b; i++) ans += dp[i];
	cout << setprecision(6) << fixed;
	cout << ans << '\n';
	return 0;
}