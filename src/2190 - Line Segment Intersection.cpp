/*
Problem Name: Line Segment Intersection
Problem Link: https://cses.fi/problemset/task/2190
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
 
ll cross(ll ax, ll ay, ll bx, ll by, ll cx, ll cy, ll dx, ll dy) {
	ll val = (ax - bx) * (cy - dy) - (ay - by) * (cx - dx);
	if (!val) return 0;
	if (val > 0) return 1;
	else return -1;
}
 
bool mid(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) {
	return (min(ax, bx) <= cx && max(ax, bx) >= cx && min(ay, by) <= cy && max(ay, by) >= cy);
}
 
bool valid() {
	ll x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	ll c1, c2, c3, c4;
	c1 = cross(x1, y1, x2, y2, x1, y1, x3, y3);
	c2 = cross(x1, y1, x2, y2, x1, y1, x4, y4);
	c3 = cross(x3, y3, x4, y4, x3, y3, x1, y1);
	c4 = cross(x3, y3, x4, y4, x4, y4, x2, y2);
	if (c1 != c2 && c3 != c4) return true;
	if (!c1 && mid(x1, y1, x2, y2, x3, y3)) return true;
	if (!c2 && mid(x1, y1, x2, y2, x4, y4)) return true;
	if (!c3 && mid(x3, y3, x4, y4, x1, y1)) return true;
	if (!c4 && mid(x3, y3, x4, y4, x2, y2)) return true;
	return false;
}
 
int main () { _
	int t;
	cin >> t;
	while (t--) {
		cout << (valid() ? "YES\n" : "NO\n");
	}
    return 0;
}