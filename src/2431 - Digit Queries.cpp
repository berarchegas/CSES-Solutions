/*
Problem Name: Digit Queries
Problem Link: https://cses.fi/problemset/task/2431
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
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
const int M = 1e9+7;
 
int main () { _
	int q;
	cin >> q;
	while (q--) {
		ll k;
		cin >> k;
		ll count = 1, minus = 9;
		while (k - minus > 0) {
			k -= minus;
			minus /= count;
			count++;
			minus *= 10 * count;
		}
		ll num = (k-1)/count + 1;
		ll base = 0, soma = 9;
		for (int i = 0; i < count-1; i++) {
			base += soma;
			soma *= 10;
		}
		string ans = to_string(base+num);
		int alga;
		if (k % count == 0) alga = count-1;
		else alga = k % count - 1;
		cout << ans[alga] << endl;
	}
	return 0;
}