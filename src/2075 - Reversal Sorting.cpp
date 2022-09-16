// Reversal Sorting
//
// Problem name: Reversal Sorting
// Problem Link: https://cses.fi/problemset/task/2075
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
const ll INF = 2e18;
 
struct node {
    node *L, *R;
    int prio, sz, val, mn;
    bool rev;
    node (int _val = MAXN) {
        L = 0, R = 0, prio = rng(), sz = 1, val = mn = _val, rev = false;
    }
};
 
int size(node *treap) {
    if (!treap) return 0;
    return treap->sz;
}
 
int mini(node *treap) {
    if (!treap) return MAXN;
    return treap->mn;
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
    treap->mn = min({treap->val, mini(treap->L), mini(treap->R)});
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
 
int query(node *treap) {
    push(treap);
    int a = mini(treap->L), b = treap->val, c = mini(treap->R), d = min({a, b, c});
    if (a == d) return query(treap->L);
    else if (b == d) return size(treap->L) + 1;
    else return size(treap->L) + 1 + query(treap->R);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n;
    node *root = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        merge(root, root, new node(x));
    }
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        //put i in its place
        
        node *a, *b, *c;
        split(root, a, b, i - 1);
        int pos = query(b);
        split(b, b, c, pos);
        b->rev ^= true;
        merge(b, b, c);
        merge(root, a, b);
        cout << i << ' ' << pos + i - 1 << endl;
    }
    return 0;
}