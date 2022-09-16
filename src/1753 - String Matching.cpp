// String Matching
//
// Problem name: String Matching
// Problem Link: https://cses.fi/problemset/task/1753
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1000100
#define INF 1e18
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 1e9+7;
 
int pre[MAXN], pwr[MAXN];
 
int main () { _
	string s1, s2;
	cin >> s1 >> s2;
	int tam1 = (int)s1.size(), tam2 = (int)s2.size();
	if (tam2 > tam1) cout << "0\n";
	else {
		pwr[0] = 1;
		int h = 0;
		for (int i = 1; i <= 1e6; i++) pwr[i] = (1ll * pwr[i-1] * 31) % M;
		for (int i = 0; i < tam1; i++) {
			if (i < tam2) 
				h = (h + (s2[i] - 'a' + 1ll) * pwr[i]) % M;
			pre[i] = ((!i ? 0 : pre[i-1]) + (s1[i] - 'a' + 1ll) * pwr[i]) % M;
		}
		int ans = 0;
		for (int i = tam2-1; i < tam1; i++) {
			ans += (((pre[i] - (i == tam2-1 ? 0 : pre[i-tam2]) + M) % M) == ((1ll * h * pwr[i-tam2+1]) % M));
		}
		cout << ans << '\n';
	}
 
    return 0;
}