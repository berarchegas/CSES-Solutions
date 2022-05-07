/*
Problem Name: Subarray Sums I
Problem Link: https://cses.fi/problemset/task/1660
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
    int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	ll soma = 0, r = 0, resp = 0;
	for (int l = 0; l < n; l++) {
		while (r < n && soma < x) {
			soma += v[r];
			r++;
		}
		if (soma == x) resp++;
		soma -= v[l];
	}
	cout << resp << '\n';
    return 0;
}