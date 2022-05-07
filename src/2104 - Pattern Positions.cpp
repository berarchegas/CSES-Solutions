/*
Problem Name: Pattern Positions
Problem Link: https://cses.fi/problemset/task/2104
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
 
#define PB push_back
 
string S;
int K, I = 1, ans[500005], sz[500005];
 
vector<int> adj[500005];
 
struct node {
    int fail, ch[26] = {}, cnt = 1e9;
    vector<int> word;
} T[500005];
 
void insert(string s, int i) {
    int x = 1;
    for (int i = 0; i < s.size(); i++) {
        if (T[x].ch[s[i] - 'a'] == 0)
            T[x].ch[s[i] - 'a'] = ++I;
        x = T[x].ch[s[i] - 'a'];
    }
    T[x].word.PB(i);
}
 
void build() {
    queue<int> Q;
    int x = 1; 
    T[1].fail = 1;
    for (int i = 0; i < 26; i++) {
        if (T[x].ch[i])
            T[T[x].ch[i]].fail = x, Q.push(T[x].ch[i]);
        else 
            T[x].ch[i] = 1;
    }
    while (!Q.empty()) {
        x = Q.front(); Q.pop();
        for (int i = 0; i < 26; i++) {
            if (T[x].ch[i])
                T[T[x].ch[i]].fail = T[T[x].fail].ch[i], Q.push(T[x].ch[i]);
            else 
                T[x].ch[i] = T[T[x].fail].ch[i];
        }
    }
    for (int i = 2; i <= I; i++)
        adj[T[i].fail].PB(i);
}
 
void run(string s) {
    for (int i = 0, x = 1; i < s.size(); i++) {
        x = T[x].ch[s[i] - 'a'];
        T[x].cnt = min(T[x].cnt, i);
    }
}
 
int dfs(int u) {
    int res = T[u].cnt;
    for (int v : adj[u])
        res = min(res, dfs(v));
    for (int w : T[u].word)
        ans[w] = res;
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> S >> K;
    for (int i = 0; i < K; i++) {
        string s; cin >> s;
        sz[i] = s.size();
        insert(s, i);
    }
 
    build();
    run(S);
    dfs(1);
 
    for (int i = 0; i < K; i++)
        cout << (ans[i] == 1e9 ? -1 : ans[i] - sz[i] + 2) << '\n';
}