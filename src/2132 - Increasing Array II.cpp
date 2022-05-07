/*
Problem Name: Increasing Array II
Problem Link: https://cses.fi/problemset/task/2132
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
 
priority_queue<int> fila;
 
int main () { _
	int n, aux;
	cin >> n;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		fila.push(aux);
		ans += fila.top() - aux;
		fila.pop();
		fila.push(aux);
	}
	cout << ans << '\n';
    return 0;
}