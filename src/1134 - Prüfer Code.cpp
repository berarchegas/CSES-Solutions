/*
Problem Name: Pr�fer Code
Problem Link: https://cses.fi/problemset/task/1134
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
 
int c[MAXN], v[MAXN];
 
int main () { _
	int n;
	cin >> n;
	for (int i = 0; i < n-2; i++) {
		cin >> v[i];
		c[v[i]]++;
	}
	priority_queue<int, vector<int>, greater<int>> fila;
	for (int i = 1; i <= n; i++) {
		if (!c[i]) fila.push(i);
	}
	for (int i = 0; i < n-2; i++) {
		cout << fila.top() << ' ' << v[i] << '\n';
		fila.pop();
		c[v[i]]--;
		if (!c[v[i]]) fila.push(v[i]);
	}
	cout << fila.top() << ' ';
	fila.pop();
	cout << fila.top() << '\n';
    return 0;
}