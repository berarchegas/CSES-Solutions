/*
Problem Name: Sum of Three Values
Problem Link: https://cses.fi/problemset/task/1641
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
 
int main() { _
    int n, k;
	cin >> n >> k;
	vector<pair<ll, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].F;
		v[i].S = i+1;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n-2; i++) {
		int r = n-1;
		for (int l = i+1; l < r; l++) {
			while (r > l + 1 && v[i].F + v[l].F + v[r].F > k) r--;
			if (v[i].F + v[r].F + v[l].F == k) {
				cout << v[i].S << ' ' << v[l].S << ' ' << v[r].S << '\n';
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
    return 0;
}