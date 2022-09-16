// Concert Tickets
//
// Problem name: Concert Tickets
// Problem Link: https://cses.fi/problemset/task/1091
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
	int n, m, aux;
	cin >> n >> m;
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		s.insert(-aux);
	}
	for (int i = 0; i < m; i++) {
		cin >> aux;
		auto it = s.begin();
		it = s.lower_bound(-aux);
		if (it == s.end()) cout << "-1\n";
		else {
			cout << -*it << '\n';
			s.erase(it);
		}
	}
	return 0;
}