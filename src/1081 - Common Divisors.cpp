// Common Divisors
//
// Problem name: Common Divisors
// Problem Link: https://cses.fi/problemset/task/1081
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1000100
#define INF 100000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9+7;
 
int main () { _
	ll n, aux;
	cin >> n;
	vector<int> v(1e6+10), c(1e6+10);
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v[aux]++;
	}
	int resp = 0;
	for (int i = 1e6; !resp &&  i > 0; i--) {
		for (int j = i; !resp && j <= 1e6; j+=i) {
			c[i]+=v[j];
			if (c[i] > 1) resp = i;
		}
	}
	cout << resp << '\n';
    return 0;   
}