// Collecting Numbers
//
// Problem name: Collecting Numbers
// Problem Link: https://cses.fi/problemset/task/2216
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 100000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9+7;
 
int main () { _
	int n;
	cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].F; 
		v[i].S = i;
	}
	sort(v.begin(), v.end());
	int resp = 1;
	for (int i = 1; i < n; i++) {
		resp += (v[i].S < v[i-1].S);
	}
	cout << resp << '\n';
	return 0;
}