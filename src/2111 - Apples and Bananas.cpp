/*
Problem Name: Apples and Bananas
Problem Link: https://cses.fi/problemset/task/2111
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
 
using cd = complex<double>;
const double PI = acos(-1);
 
void fft(vector<cd> & a, bool invert) {
    int n = a.size();
 
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
 
        if (i < j)
            swap(a[i], a[j]);
    }
 
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
 
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
 
vector<ll> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int)(a.size() + b.size())) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
 
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
 
    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}
 
int main() { _
	int k, n, m, aux;
	cin >> k >> n >> m;
	vector<int> ban(k), ap(k);
	for (int i = 0; i < n; i++) {
		cin >> aux;
		ban[aux-1]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> aux;
		ap[aux-1]++;
	}
	vector<ll> ans = multiply(ban, ap);
	for (int i = 0; i < 2*k-1; i++) cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}