/*
Problem Name: List Removals
Problem Link: https://cses.fi/problemset/task/1749
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 1e17
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 998244353;
 
int a[4*MAXN];
 
void build(int node, int i, int j) {
	if (i == j) a[node] = 1;
	else {
		int m = (i+j)/2;
		build(2*node, i, m);
		build(2*node+1, m+1, j);
		a[node] = a[2*node] + a[2*node+1];
	}
}
 
int ans(int node, int i, int j, int k) {
	a[node]--;
	if (i == j) {
		return i;
	}
	else {
		int m = (i+j)/2;
		if (a[2*node] >= k) 
			return ans(2*node, i, m, k);
		else 
			return ans(2*node+1, m+1, j, k-a[2*node]);
	}
}
 
int main () { _
	int n, aux;
	cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	build(1, 1, n);
	for (int i = 0; i < n; i++) {
		cin >> aux;
		cout << v[ans(1, 1, n, aux)] << ' ';
	}	
	cout << '\n';
	return 0;
}