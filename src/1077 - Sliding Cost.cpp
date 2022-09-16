// Sliding Cost
//
// Problem name: Sliding Cost
// Problem Link: https://cses.fi/problemset/task/1077
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 1000000001
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
 
int main () { _
	int n, k;
    cin >> n >> k;
    vector<int> v(n);
    multiset<ll> menor, maior, aux;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i < k) aux.insert(v[i]);
    }
    int count = 0;
    ll mi = 0, mj = 0;
    for (int x : aux) {
        if (count < (k+1)/2) {
            menor.insert(x);
            mi += x;
        }
        else {
            maior.insert(x);
            mj += x;
        }
        count++;
    }
    cout << abs(mi - (int)menor.size() * *menor.rbegin()) + abs(mj - (int)maior.size() * *menor.rbegin()) << ' ';
    for (int i = k; i < n; i++) {
        if (maior.find(v[i-k]) != maior.end()) {
            maior.erase(maior.find(v[i-k]));
            mj -= v[i-k];
        }
        else {
            menor.erase(menor.find(v[i-k]));
            mi -= v[i-k];
        }
        if (menor.empty() || v[i] > *menor.rbegin()) {
            maior.insert(v[i]);
            mj += v[i];
        }
        else {
            menor.insert(v[i]);
            mi += v[i];
        }
        while (maior.size() > menor.size()) {
            menor.insert(*maior.begin());
            mi += *maior.begin();
            mj -= *maior.begin();
            maior.erase(maior.begin());
        }
        while (menor.size()-1 > maior.size()) {
            auto it = menor.end();
            it--;
            mi -= *it;
            mj += *it;
            maior.insert(*it);
            menor.erase(it);
        }
        cout << abs(mi - (int)menor.size() * *menor.rbegin()) + abs(mj - (int)maior.size() * *menor.rbegin()) << ' ';
    }
    cout << '\n';
	return 0;	
}