/*
Problem Name: Bit Inversions
Problem Link: https://cses.fi/problemset/task/1188
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
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
 
struct t{
	int pre, suf, ans, tam;
};
 
string s;
t a[4*MAXN][2];
 
void merge(int node) {
	a[node][0].tam = a[2*node][0].tam + a[2*node+1][0].tam;
	if (a[2*node][0].pre == a[2*node][0].tam) 
		a[node][0].pre = a[2*node][0].pre + a[2*node+1][0].pre;
	else a[node][0].pre = a[2*node][0].pre;
 
	if (a[2*node][1].pre == a[2*node][0].tam) 
		a[node][1].pre = a[2*node][1].pre + a[2*node+1][1].pre;
	else a[node][1].pre = a[2*node][1].pre;
 
	if (a[2*node+1][0].suf == a[2*node+1][0].tam) 
		a[node][0].suf = a[2*node][0].suf + a[2*node+1][0].suf;
	else a[node][0].suf = a[2*node+1][0].suf;
 
	if (a[2*node+1][1].suf == a[2*node+1][0].tam) 
		a[node][1].suf = a[2*node][1].suf + a[2*node+1][1].suf;
	else a[node][1].suf = a[2*node+1][1].suf;
 
	a[node][0].ans = max({a[node][0].pre, a[node][0].suf, a[2*node][0].ans, a[2*node+1][0].ans, a[2*node][0].suf + a[2*node+1][0].pre});
	a[node][1].ans = max({a[node][1].pre, a[node][1].suf, a[2*node][1].ans, a[2*node+1][1].ans, a[2*node][1].suf + a[2*node+1][1].pre});
}
 
void build(int node, int i, int j) {
	if (i == j) {
		a[node][0].ans = a[node][0].pre = a[node][0].suf = (s[i] == '0');
		a[node][1].ans = a[node][1].pre = a[node][1].suf = (s[i] == '1');
		a[node][0].tam = 1;
	}
	else {
		int m = (i+j)/2;
		build(2*node, i, m);
		build(2*node+1, m+1, j);
		merge(node);
	}
}
 
void upd(int node, int i, int j, int pos) {
	if (i == j) {
		a[node][0].ans = a[node][0].pre = a[node][0].suf = (s[i] == '0');
		a[node][1].ans = a[node][1].pre = a[node][1].suf = (s[i] == '1');
	}
	else {
		int m = (i+j)/2;
		if (m >= pos) upd(2*node, i, m, pos);
		else upd(2*node+1, m+1, j, pos);
		merge(node);
	}
}
 
int main () { _
	cin >> s;
	int n = (int)s.size();
	build(1, 0, n-1);
	int q;
	cin >> q;
	int pos;
	for (int i = 0; i < q; i++) {
		cin >> pos;
		pos--;
		s[pos] = (s[pos] == '1' ? '0' : '1');
		upd(1, 0, n-1, pos);
		cout << max(a[1][0].ans, a[1][1].ans) << ' ';
	}
	cout << '\n';
    return 0;
}