/*
Problem Name: Josephus Problem II
Problem Link: https://cses.fi/problemset/task/2163
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1000100
#define INF 100000000
#define pb push_back
#define F first
#define S second
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> ordered_set;
const int M = 1e9+7;
 
int main () { _
    int n, k;
    cin >> n >> k;
    ordered_set s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    int tam = n, pos = k % tam;
    for (int i = 0; i < n; i++) {
        auto x = s.find_by_order(pos);
        cout << *x << ' ';
        s.erase(*x);
        tam--;
        if (tam) pos = (pos + k) % tam;
    }
    cout << '\n';
    return 0;   
}