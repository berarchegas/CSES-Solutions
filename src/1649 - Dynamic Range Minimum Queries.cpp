/*
Problem Name: Range Minimum Queries II
Problem Link: https://cses.fi/problemset/task/1649
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 10000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
 
int n, q, a, b, v[MAXN], arvore[4*MAXN];
 
void build(int node, int i, int j) {
	if (i == j) arvore[node] = v[i];
	else {
		int meio = (i+j)/2;
		build(2*node, i, meio);
		build(2*node+1, meio+1, j);
		arvore[node] = min(arvore[2*node], arvore[2*node+1]);
	}
}
 
void atualiza(int node, int i, int j, int posicao, int novo) {
	if (i == j) { 
		v[posicao] = novo;
		arvore[node] = novo;
	}
	else {
		int meio = (i+j)/2;
		if (posicao > meio) atualiza(2*node+1, meio+1, j, posicao, novo);
		else atualiza(2*node, i, meio, posicao, novo);
		arvore[node] = min(arvore[2*node], arvore[2*node+1]);
	}
}
 
int consulta (int node, int i, int j, int ini, int fim) {
	if (i > fim || j < ini) return INT_MAX;
	if (i >= ini && j <= fim) return arvore[node];
	else {
		int meio = (i+j)/2;
		int resp1 = consulta (2*node, i, meio, ini, fim);
		int resp2 = consulta (2*node+1, meio+1, j, ini, fim);
		return min(resp1, resp2);
	}
}
 
int main () { _
	int tipo;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	build(1, 1, n);
	for (int i = 0; i < q; i++) {
		cin >> tipo >>  a >> b;
		if (tipo == 1) 
			atualiza (1, 1, n, a, b);
		else 
			cout << consulta(1, 1, n, a, b) << endl;
	}
    return 0;
}