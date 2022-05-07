/*
Problem Name: Beautiful Subgrids
Problem Link: https://cses.fi/problemset/task/2137
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#pragma GCC target("popcnt")
#include <iostream>
#include <bitset>
using namespace std;
const int N = 3000;
bitset<N> v[N];
string s;
int main () {
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v[i] = bitset<N>(s);
	}
	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int tot = (v[i] & v[j]).count();
			ans += (tot * (tot-1))/2;
		}
	}
	cout << ans << '\n';
	return 0;
}