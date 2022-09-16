// Moving Robots
//
// Problem name: Moving Robots
// Problem Link: https://cses.fi/problemset/task/1726
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 100000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
 
bool valid(int x, int y) { return (x >= 0 && x < 8 && y >= 0 && y < 8); }
 
int main () { _
	int n;
	cin >> n;
	vector<vector<int>> count(8, vector<int> (8));
	vector<vector<vector<pii>>> moves(8, vector<vector<pii>> (8));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 4; k++) {
				if (valid(i + dx[k], j + dy[k])) {
					count[i][j]++;
					moves[i][j].pb({i+dx[k], j+dy[k]});
				}
			}
		}
	}
	vector<vector<double>> ans(8, vector<double> (8, 1.0));
	for (int l = 0; l < 8; l++) {
		for (int m = 0; m < 8; m++) {
			vector<vector<double>> v(8, vector<double> (8)), w(8, vector<double> (8));
			v[l][m] = 1;
			for (int k = 0; k < n; k++) {
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						for (int a = 0; a < (int)moves[i][j].size(); a++) {
							w[moves[i][j][a].F][moves[i][j][a].S] += v[i][j] / count[i][j];
						}
					}
				}
				v = w;
				fill(w.begin(), w.end(), vector<double> (8));
			}
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					ans[i][j] *= (1.0 - v[i][j]);
				}
			}
		}
	}
	double resp = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			resp += ans[i][j];
		}
	}
	cout << setprecision(6) << fixed;
	cout << resp << '\n';
	return 0;
}