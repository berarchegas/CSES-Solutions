/*
Problem Name: Array Division
Problem Link: https://cses.fi/problemset/task/1085
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
    int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	ll l = 0, r = 1e16;
	while (r > l + 1) {
		ll m = (r+l)/2;
		ll count = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			if (sum + v[i] <= m) sum += v[i];
			else {
				sum = v[i];
				if (sum > m) count = 1e8;
				count++;
			}
		}
		count += (sum > 0);
		if (count <= k) r = m;
		else l = m;
	}	
	cout << r << '\n';
    return 0;
}