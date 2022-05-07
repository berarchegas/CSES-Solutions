/*
Problem Name: Playlist
Problem Link: https://cses.fi/problemset/task/1141
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
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
	int n;
	cin >> n;
	vector<int> v(n);
	map<int, int> mapa;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int r = 0, resp = 0;
	mapa[v[0]]++;
	for (int l = 0; l < n; l++) {
		while (r < n && mapa[v[r]] <= 1) {
			resp = max(resp, r - l + 1);
			r++;
			mapa[v[r]]++;
		}
		mapa[v[l]]--;
	}
	cout << resp << '\n';
	return 0;
}