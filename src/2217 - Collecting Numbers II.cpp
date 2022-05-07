/*
Problem Name: Collecting Numbers II
Problem Link: https://cses.fi/problemset/task/2217
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 300100
#define INF 100000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9+7;
 
map<int, int> mp;
 
int count(int a, int b, vector<int> &w) {
    if (a > b) swap(a, b);
    int ans = 0;
    ans += w[a-1] > w[a];
    ans += w[b] > w[b+1];
    if (a+1 == b) {
        ans += w[a] > w[b];
    }
    else {
        ans += w[a] > w[a+1];
        ans += w[b-1] > w[b];
    }
    return ans;
}
 
int main() { _
    int n, m;
    cin >> n >> m;
    vector<pii> v(n+2);
    vector<int> w;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].F;
        v[i].S = i;
        mp[i] = v[i].F; 
    }
    v[n+1] = {n+1, n+1};
    sort(v.begin(), v.end());
    for (int i = 0; i < n+2; i++) {
        w.pb(v[i].S);
    }
    int resp = 1;
    for (int i = 1; i <= n; i++) {
        resp += (w[i-1] > w[i]);
    }
    for (int i = 0; i < m; i++) {
        int a, b, ma, mb, aux;
        cin >> a >> b;
        ma = mp[a], mb = mp[b];
        aux = ma;
        mp[a] = mp[b];
        mp[b] = aux;
        int antes = count(ma, mb, w);
        swap(w[ma], w[mb]);
        int dif = count(ma, mb, w) - antes;
        resp += dif;
        cout << resp << '\n';
    }
	return 0;
}