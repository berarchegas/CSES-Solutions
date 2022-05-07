/*
Problem Name: Permutations
Problem Link: https://cses.fi/problemset/task/1070
Author: Bernardo Archegas (codeforces.com/profile/Ber)
*/
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
const int M = 1e9+7;
 
int main () { _
	int n;
	cin >> n;
	if (n == 1) cout << "1\n";
	else if (n < 4) cout << "NO SOLUTION\n";
	else {
		int start = n/2 + 1;
		for (int i = 1; i < start; i++) {
			cout << start + i - 1 << " " << i << " ";
		}
		if (n % 2 == 1) cout << 2*start - 1;
		cout << "\n";
	}
	return 0;
}