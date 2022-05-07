/*
Problem Name: Hamming Distance
Problem Link: https://cses.fi/problemset/task/2136
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
    int n, k;
	cin >> n >> k;
	vector<pii> v(n);
	string s;
	cin >> s;
	v[0].S = stoi(s, nullptr, 2);
	int resp = k;
	for (int i = 1; i < n; i++) {
		cin >> s;
		v[i].S = stoi(s, nullptr, 2);
		v[i].F = __builtin_popcount(v[0].S ^ v[i].S);
		resp = min(resp, v[i].F);
	}	
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (v[j].F < v[i].F + resp) {
				resp = min(resp, __builtin_popcount(v[j].S ^ v[i].S));
			}
			else break;
		}
	}
	cout << resp << '\n';
    return 0;
}