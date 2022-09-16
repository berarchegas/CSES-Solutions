// Subarray Distinct Values
//
// Problem name: Subarray Distinct Values
// Problem Link: https://cses.fi/problemset/task/2428
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

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
	map<int, int> mapa;
	ll resp = 0;
	int r = 0, dist = 0;
	for (int l = 0; l < n; l++) {
		while (r < n && dist <= k) {
			mapa[v[r]]++;
			if (mapa[v[r]] == 1) dist++;
			r++;
		}
		resp += (r-l);
		if (dist > k) resp--;
		mapa[v[l]]--;
		if (mapa[v[l]] == 0) dist--;
	}
	cout << resp << '\n';
    return 0;
}