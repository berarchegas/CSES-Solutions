// Shortest Subsequence
//
// Problem name: Shortest Subsequence
// Problem Link: https://cses.fi/problemset/task/1087
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 2000100
#define INF 1000000001
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 998244353;
 
int main () { _
	string s, resp;
	cin >> s;
	int tam = s.size();
	set<char> st;
	int ans = 0;
	for (int i = 0; i < tam; i++) {
		st.insert(s[i]);
		if ((int)st.size() == 4) {
			resp += s[i];
			ans++;
			st.clear();
		}
	}
	if (!st.count('A')) resp += 'A';
	else if (!st.count('C')) resp += 'C';
	else if (!st.count('G')) resp += 'G';
	else resp += 'T';
	cout << resp << '\n';
	return 0;	
}