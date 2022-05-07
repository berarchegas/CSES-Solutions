/*
Problem Name: Nested Ranges Count
Problem Link: https://cses.fi/problemset/task/2169
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 400100
#define INF 1000000001
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
 
int a[MAXN];
 
void upd(int pos) {
    for (int i = pos; i < MAXN; i+=(i & -i)) {
        a[i]++;
    }
}
 
int sum(int pos) {
    int resp = 0;
    for (int i = pos; i > 0; i-=(i & -i)) {
        resp += a[i];
    }
    return resp;
}
 
int main () { _
    int n;
    cin >> n;
    vector<pair<pii, int>> v(n);
    set<int> comp;
    for (int i = 0; i < n; i++) {
        cin >> v[i].F.F >> v[i].F.S;
        v[i].S = i;
        comp.insert(v[i].F.F), comp.insert(v[i].F.S);
    }   
    map<int,int> mp;
    int atual = 1;
    for (int x : comp) {
        mp[x] = atual++;
    }
    for (int i = 0; i < n; i++) {
        v[i].F.F = mp[v[i].F.F];
        v[i].F.S = mp[v[i].F.S];
    }
    sort(begin(v), end(v), [&](pair<pii, int> a, pair<pii, int> b) {
        if (a.F.F == b.F.F) return a.F.S > b.F.S;
        return a.F.F < b.F.F;
    });
    vector<pii> contem(n), contido(n);
    for (int i = n-1; i >= 0; i--) {
        contem[i].S = sum(v[i].F.S);
        contem[i].F = v[i].S;
        upd(v[i].F.S);
    }
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
        contido[i].S = sum(MAXN-1) - sum(v[i].F.S - 1);
        contido[i].F = v[i].S;
        upd(v[i].F.S);
    }
    sort(begin(contem), end(contem));
    sort(begin(contido), end(contido));
    for (pii x : contem) cout << x.S << ' ';
    cout << '\n';
    for (pii x : contido) cout << x.S << ' ';
    cout << '\n';
	return 0;	
}