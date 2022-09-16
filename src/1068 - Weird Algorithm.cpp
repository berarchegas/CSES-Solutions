// Weird Algorithm
//
// Problem name: Weird Algorithm
// Problem Link: https://cses.fi/problemset/task/1068
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

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
	ll n;
	cin >> n;
	while (n != 1) {
		cout << n << " ";
		if (n % 2 == 0) n /= 2;
		else n = 3 * n + 1;
	}
	cout << n << "\n";
	return 0;
}