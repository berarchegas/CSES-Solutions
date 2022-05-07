/*
Problem Name: Repetitions
Problem Link: https://cses.fi/problemset/task/1069
Author: Bernardo Archegas (codeforces.com/profile/Ber)
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
	string s;
	cin >> s;
	int ans = 1;
	int count = 1;
	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] == s[i-1]) count++;
		else {
			ans = max(ans, count);
			count = 1;
		}
	}
	ans = max(ans, count);
	cout << ans << "\n";
	return 0;
}