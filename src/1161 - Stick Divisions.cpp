/*
Problem Name: Stick Divisions
Problem Link: https://cses.fi/problemset/task/1161
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
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
 
int main () { _
	int x, n;
	cin >> x >> n;
	vector<int> v(n);
	priority_queue<int, vector<int>, greater<int>> fila;
	for (int &x : v) {
		cin >> x;
		fila.push(x);
	}
	ll ans = 0;
	int a, b;
	while (fila.size() > 1) {
		a = fila.top();
		fila.pop();
		b = fila.top();
		fila.pop();
		ans += a + b;
		fila.push(a+b);
	}
	cout << ans << '\n';
    return 0;
}