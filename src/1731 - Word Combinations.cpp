/*
Problem Name: Word Combinations
Problem Link: https://cses.fi/problemset/task/1731
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
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
 
int dp[5050], trie[MAXN][26], quant[MAXN], fim[MAXN], cnt = 0, n;
string s;
 
void insert(string &a) {
	int node = 0;
	for (char c : a) {
		quant[node]++;
		if (!trie[node][c-'a']) trie[node][c-'a'] = ++cnt;
		node = trie[node][c - 'a'];
	}
	quant[node]++;
	fim[node]++;
}
 
int query(int x) {
	int ans = 0, node = 0;
	for (int i = x; i < n; i++) {
		if (!trie[node][s[i] - 'a']) return ans;
		node = trie[node][s[i] - 'a'];
		ans = (ans + 1ll * fim[node] * dp[i+1]) % M;
	}
	return ans;
}
 
int main () { _
	string aux;
	cin >> s;
	n = (int)s.size();
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> aux;
		insert(aux);
	}
	dp[n] = 1;
	for (int i = n-1; i >= 0; i--) 
		dp[i] = query(i);
	
	cout << dp[0] << '\n';
    return 0;
}