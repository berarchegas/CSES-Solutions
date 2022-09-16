// Maximum Xor Subarray
//
// Problem name: Maximum Xor Subarray
// Problem Link: https://cses.fi/problemset/task/1655
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

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
 
int trie[6000100][2], quant[6000100], cnt = 0;
 
void insert(int x) {
	int no = 0;
	for (int i = 30; i >= 0; i--) {
		quant[no]++;
		if (quant[no] == 1) {
			trie[no][0] = ++cnt;
			trie[no][1] = ++cnt;
		}
		no = trie[no][(x & (1<<i) ? 1 : 0)];
	}
	quant[no]++;
}
 
int query(int x) {
	int no = 0, resp = 0;
	for (int i = 30; i >= 0; i--) {
		if (quant[trie[no][(x & (1<<i) ? 0 : 1)]]) {
			resp += (x & (1<<i) ? 0 : 1) * (1<<i);
			no = trie[no][(x & (1<<i) ? 0 : 1)];
		}
		else {
			resp += (x & (1<<i) ? 1 : 0) * (1<<i);
			no = trie[no][(x & (1<<i) ? 1 : 0)];
		}
	}
	return resp;
}
 
int main () { _
	int n;
	cin >> n;
	int ans = 0, atual = 0, aux;
	insert(0);
	for (int i = 0; i < n; i++) {
		cin >> aux;
		atual ^= aux;
		ans = max(ans, query(atual) ^ atual);
		insert(atual);
	}	
	cout << ans << '\n';
    return 0;
}
