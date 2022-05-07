/*
Problem Name: Nearest Smaller Values
Problem Link: https://cses.fi/problemset/task/1645
Author: Bernardo Archegas (codeforces/profile/Ber)
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
 
int main() { _
    int n;
	cin >> n;
	vector<int> v(n+1), ans(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		ans[i] = i-1;
	}
	for (int i = 1; i <= n; i++) {
		while (v[ans[i]] >= v[i]) {
			ans[i] = ans[ans[i]];
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << '\n';
    return 0;
}