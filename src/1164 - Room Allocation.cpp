// Room Allocation
//
// Problem name: Room Allocation
// Problem Link: https://cses.fi/problemset/task/1164
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

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
 
struct t {
	int f, s;
	bool sair;
};
 
int main() { _
    int n;
	t aux;
	cin >> n;
	vector<t> v;
	vector<int> w(n, -1);
	for (int i = 0; i < n; i++) {
		cin >> aux.f >> aux.s;
		int depois = aux.s;
		aux.s = i;
		aux.sair = false;
		v.pb(aux);
		aux.f = depois+1;
		aux.sair = true;
		v.pb(aux);
	}
	int tot = 1;
	queue<int> q;
	sort(v.begin(), v.end(), [&](t a, t b) { 
		if (a.f != b.f) return a.f < b.f;
		return (a.sair && !b.sair);
	});
	for (t x : v) {
		if (w[x.s] == -1) {
			if (q.empty()) {
				w[x.s] = tot++;
			}
			else {
				w[x.s] = q.front();
				q.pop();
			}
		}
		else {
			q.push(w[x.s]);
		}
	}
	cout << tot-1 << '\n';
	sort(v.begin(), v.end(), [&](t a, t b) {
		return a.s < b.s;
	});
	bool ber = true;
	for (t x : v) {
		if (ber)
			cout << w[x.s] << ' ';
		ber = 1-ber;
	}
	cout << '\n';
    return 0;
}