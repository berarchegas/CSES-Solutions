/*
Problem Name: Bit Substrings
Problem Link: https://cses.fi/problemset/task/2115
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
const ll INF = 1e18;
 
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
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> v, w;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            v.push_back(cnt+1);
            cnt = 0;
        }
        else cnt++;
    }
    v.push_back(cnt+1);
    w = v;
    reverse(w.begin(), w.end());
    vector<ll> ans = multiply(v, w);
    ll zero = 0;
    for (int x : v) zero += (1ll * x * (x-1) / 2);
    cout << zero << ' ';
    int tot = 1;
    for (int i = (int)v.size(); i < (int)ans.size() && tot < n+1; i++) {
        cout << ans[i] << ' ';
        tot++;
    }
    while (tot < n+1) {
        cout << "0 ";
        tot++;
    }
    cout << '\n';
    return 0;
}