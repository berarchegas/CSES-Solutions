/*
Problem Name: Towers
Problem Link: https://cses.fi/problemset/task/1073
Author: Bernardo Archegas (codeforces/profile/Ber)
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
 
int main () { _
	int n, aux;
	cin >> n;
	vector<int> pilha;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		auto it = upper_bound(pilha.begin(), pilha.end(), aux);
		if (it == pilha.end()) pilha.pb(aux);
		else *it = aux;
	}
	cout << pilha.size() << '\n';
	return 0;
}