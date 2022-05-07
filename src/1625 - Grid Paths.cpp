/*
Problem Name: Grid Paths
Problem Link: https://cses.fi/problemset/task/1625
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1e6+2
#define INF 1000000001
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9+7;
 
string s;
int check[7][7], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
char c[4] = {'D', 'U', 'R', 'L'};
bool valid(int x, int y) { return (x >= 0 && x < 7 && y >= 0 && y < 7 && !check[x][y]); }
bool miou(int x, int y) {
	if (x == 6 && y == 0) return true;
	if (valid(x+1, y) && valid(x-1, y) && !valid(x, y+1) && !valid(x, y-1)) return true;
	if (!valid(x+1, y) && !valid(x-1, y) && valid(x, y+1) && valid(x, y-1)) return true;
	if (valid(x+1, y) && valid(x, y+1) && !valid(x+1, y+1)) return true;
	if (valid(x+1, y) && valid(x, y-1) && !valid(x+1, y-1)) return true;
	if (valid(x-1, y) && valid(x, y-1) && !valid(x-1, y-1)) return true;
	if (valid(x-1, y) && valid(x, y+1) && !valid(x-1, y+1)) return true;
	return false;
}
 
int count(int x, int y, int pos) {
	if (pos == 48) return 1;
	int ans = 0;
	if (miou(x, y)) return 0;
	check[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		if (valid(x + dx[i], y + dy[i]) && (s[pos] == '?' || s[pos] == c[i]))
			ans += count(x + dx[i], y + dy[i], pos + 1);
	}
	check[x][y] = 0;
	return ans;
}
 
int main () { _
	cin >> s;
	cout << count(0, 0, 0) << '\n';
	return 0;
}