// Tasks and Deadlines
//
// Problem name: Tasks and Deadlines
// Problem Link: https://cses.fi/problemset/task/1630
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

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
 
int main() { _
    int n, aux;
    cin >> n;
    ll soma = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> aux;
        soma += aux;
    }
    sort(v.begin(), v.end());
    ll tempo = 0;
    for (int i = 0; i < n; i++) {
        tempo += v[i];
        soma -= tempo;
    }
    cout << soma << '\n';
	return 0;
}