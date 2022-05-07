/*
Problem Name: Josephus Problem I
Problem Link: https://cses.fi/problemset/task/2162
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
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
 
set<int> s;
 
int main() { _
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) s.insert(i);
    auto it = s.begin();
    it++;
    int count = 0;
    while (count < n) {
        cout << *it << ' ';
        auto it2 = it;
        it++;
        if (it == s.end()) it = s.begin();
        s.erase(*it2);
        it++;
        if (it == s.end()) it = s.begin();
        count++;
    }
    cout << '\n';
	return 0;
}