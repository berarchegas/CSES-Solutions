/*
Problem Name: Apartments
Problem Link: https://cses.fi/problemset/task/1084
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 999999
 
using namespace std;
typedef long long int lli;
 
int main() {
	int n, m, k, ap[MAXN], v[MAXN], resp = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> ap[i];
	}
	sort(v, v+n);
	sort(ap, ap+m);
	int id = 0;
	for (int i = 0; i < n && id < m; i++) {
		while (v[i] > ap[id]+k and id < m) id++;
		if (v[i] < ap[id]-k) continue;
		if (id < m) resp++;
		id++;
	}
	cout << resp << endl;
	return 0;
}