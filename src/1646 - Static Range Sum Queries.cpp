/*
Problem Name: Range Sum Queries I
Problem Link: https://cses.fi/problemset/task/1646
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 10000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
 
int main () { _
	int n, q, a, b;
	lli v[MAXN];
	cin >> n >> q;
	v[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		v[i] += v[i-1];
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		cout << v[b] - v[a-1] << endl;
	}
    return 0;
}