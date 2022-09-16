// Book Shop II
//
// Problem name: Book Shop II
// Problem Link: https://cses.fi/problemset/task/1159
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const ll INF = 1e18;
 
int cop[MAXN], pr[MAXN], pg[MAXN], dp[MAXN];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) 
        cin >> pr[i];
    for (int i = 0; i < n; i++) 
        cin >> pg[i];  
    
    vector<int> pages, price;
    for (int i = 0; i < n; i++) {
        cin >> cop[i];
        int tot = 0;
        for (int j = 0; j < 10; j++) {
            if (cop[i] >= (1 << (j+1))) {
                pages.push_back(pg[i] * (1<<j));
                price.push_back(pr[i] * (1<<j));
                tot += (1<<j);
            }
        }
        pages.push_back(pg[i] * (cop[i] - tot));
        price.push_back(pr[i] * (cop[i] - tot));
    }
    int m = (int)pages.size();
    for (int i = 0; i < m; i++) {
        for (int j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j-price[i]] + pages[i], dp[j]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= x; i++) ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}