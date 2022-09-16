// Substring Reversals
//
// Problem name: Substring Reversals
// Problem Link: https://cses.fi/problemset/task/2073
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 5;
const ll INF = 2e18;
 
struct node {
    node *L, *R;
    int prio, sz;
    char c;
    bool rev;
    node (char _c) {
        L = 0, R = 0, prio = rng(), sz = 1, c = _c, rev = false;
    }
};
 
int size(node *treap) {
    if (!treap) return 0;
    return treap->sz;
}
 
void push(node *treap) {
    if (treap && treap->rev) {
        treap->rev = false;
        swap(treap->L, treap->R);
        if (treap->L) treap->L->rev ^= true;
        if (treap->R) treap->R->rev ^= true;
    }
}
 
void recalc(node *&treap) {
    if (!treap) return;
    treap->sz = size(treap->L) + size(treap->R) + 1;
}
 
void split(node *treap, node *&L, node *&R, int k) {
    if (!treap) {
        L = R = 0;
    }
    else {
        push(treap);
        if (size(treap->L) >= k) {
            split(treap->L, L, treap->L, k);
            R = treap;
        }
        else {
            split(treap->R, treap->R, R, k - size(treap->L) - 1);
            L = treap;
        }
        recalc(treap);
    }
}
 
void merge(node *&treap, node *L, node *R) {
    if (!L) treap = R;
    else if (!R) treap = L;
    else {
        push(L), push(R);
        if (L->prio > R->prio) {
            merge(L->R, L->R, R);
            treap = L;
        }
        else {
            merge(R->L, L, R->L);
            treap = R;
        }
        recalc(treap);
    }
}
 
void print(node *treap) {
    if (!treap) return;
    push(treap);
    print(treap->L);
    cout << treap->c;
    print(treap->R);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, l, r;
    string s;
    cin >> n >> m >> s;
    node *root = 0;
    for (int i = 0; i < n; i++) {
        merge(root, root, new node(s[i]));
    }
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        node *a, *b, *c;
        split(root, a, b, l - 1);
        split(b, b, c, r - l + 1);
        b->rev ^= true;
        merge(root, a, b);
        merge(root, root, c);
    }
    print(root);
    cout << '\n';
    return 0;
}