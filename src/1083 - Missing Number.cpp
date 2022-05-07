/*
Problem Name: Missing Number
Problem Link: https://cses.fi/problemset/task/1083
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
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
	int n, aux;
	cin >> n;
	vector<int> check(n+1);
	for (int i = 0; i < n - 1; i++) {
		cin >> aux;
		check[aux] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}