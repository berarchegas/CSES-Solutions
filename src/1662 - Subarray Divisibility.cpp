/*
Problem Name: Subarray Divisibility
Problem Link: https://cses.fi/problemset/task/1662
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
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	map<int, int> mp;
	ll soma = 0, resp = 0;
	mp[0] = 1;
	for (int i = 0; i < n; i++) {
		soma = (soma + v[i]) % n;
		if (soma < 0) soma += n;
		resp += mp[soma % n];
		mp[soma % n]++;
	}
	cout << resp << '\n';
    return 0;
}