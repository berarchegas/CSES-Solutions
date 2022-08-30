/*
Problem Name: Grid Puzzle II
Problem Link: https://cses.fi/problemset/task/2131
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
const ll INF = 2e18;
 
// MinCostMaxFlow
//
// min_cost_flow(s, t, f) computa o par (fluxo, custo)
// com max(fluxo) <= f que tenha min(custo)
// min_cost_flow(s, t) -> Fluxo maximo de custo minimo de s pra t
// Se for um dag, da pra substituir o SPFA por uma DP pra nao
// para O(nm) no comeco
// Se nao tiver aresta com custo negativo, nao precisa do SPFA
//
// O(nm + f * m log n)
// 697b4c
 
template<typename T = int> struct mcmf {
	struct edge {
		int to, rev, flow, cap; // para, id da reversa, fluxo, capacidade
		bool res; // se eh reversa
		T cost; // custo da unidade de fluxo
		edge() : to(0), rev(0), flow(0), cap(0), cost(0), res(false) {}
		edge(int to_, int rev_, int flow_, int cap_, T cost_, bool res_)
			: to(to_), rev(rev_), flow(flow_), cap(cap_), res(res_), cost(cost_) {}
	};
 
	vector<vector<edge>> g;
	vector<int> par_idx, par;
	T inf;
	vector<T> dist;
 
	mcmf(int n) : g(n), par_idx(n), par(n), inf(numeric_limits<T>::max()/3) {}
 
	void add(int u, int v, int w, T cost) { // de u pra v com cap w e custo cost
		edge a = edge(v, g[v].size(), 0, w, cost, false);
		edge b = edge(u, g[u].size(), 0, 0, -cost, true);
 
		g[u].push_back(a);
		g[v].push_back(b);
	}
 
	vector<T> spfa(int s) { // nao precisa se nao tiver custo negativo
		deque<int> q;
		vector<bool> is_inside(g.size(), 0);
		dist = vector<T>(g.size(), inf);
 
		dist[s] = 0;
		q.push_back(s);
		is_inside[s] = true;
 
		while (!q.empty()) {
			int v = q.front();
			q.pop_front();
			is_inside[v] = false;
 
			for (int i = 0; i < g[v].size(); i++) {
				auto [to, rev, flow, cap, res, cost] = g[v][i];
				if (flow < cap and dist[v] + cost < dist[to]) {
					dist[to] = dist[v] + cost;
 
					if (is_inside[to]) continue;
					if (!q.empty() and dist[to] > dist[q.front()]) q.push_back(to);
					else q.push_front(to);
					is_inside[to] = true;
				}
			}
		}
		return dist;
	}
	bool dijkstra(int s, int t, vector<T>& pot) {
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> q;
		dist = vector<T>(g.size(), inf);
		dist[s] = 0;
		q.emplace(0, s);
		while (q.size()) {
			auto [d, v] = q.top();
			q.pop();
			if (dist[v] < d) continue;
			for (int i = 0; i < g[v].size(); i++) {
				auto [to, rev, flow, cap, res, cost] = g[v][i];
				cost += pot[v] - pot[to];
				if (flow < cap and dist[v] + cost < dist[to]) {
					dist[to] = dist[v] + cost;
					q.emplace(dist[to], to);
					par_idx[to] = i, par[to] = v;
				}
			}
		}
		return dist[t] < inf;
	}
 
	pair<int, T> min_cost_flow(int s, int t, int flow) {
		vector<T> pot(g.size(), 0);
		pot = spfa(s); // mudar algoritmo de caminho minimo aqui
 
		int f = 0;
		T ret = 0;
		while (f < flow and dijkstra(s, t, pot)) {
			for (int i = 0; i < g.size(); i++)
				if (dist[i] < inf) pot[i] += dist[i];
 
			int mn_flow = flow - f, u = t;
			while (u != s){
				mn_flow = min(mn_flow,
					g[par[u]][par_idx[u]].cap - g[par[u]][par_idx[u]].flow);
				u = par[u];
			}
 
			ret += pot[t] * mn_flow;
 
			u = t;
			while (u != s) {
				g[par[u]][par_idx[u]].flow += mn_flow;
				g[u][g[par[u]][par_idx[u]].rev].flow -= mn_flow;
				u = par[u];
			}
 
			f += mn_flow;
		}
 
		return make_pair(f, ret);
	}
 
	// Opcional: retorna as arestas originais por onde passa flow = cap
	vector<pair<int,int>> recover() {
		vector<pair<int,int>> used;
		for (int i = 0; i < g.size(); i++) for (edge e : g[i])
			if(e.flow == e.cap && !e.res) used.push_back({i, e.to});
		return used;
	}
};
 
int resp[55][55];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n;
    mcmf ber(2 * n + 2);
    int fluxo = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        fluxo += x;
        ber.add(0, i, x, 0);
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        cin >> x;
        ber.add(i, 2*n + 1, x, 0);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            ber.add(i + 1, n + j + 1, 1, -x);
        }
    }
    pii ans = ber.min_cost_flow(0, 2 * n + 1, ber.inf);
    if (ans.first < fluxo) cout << "-1\n";
    else {
        cout << -ans.second << '\n';
        vector<pii> ed = ber.recover();
        for (auto x : ed) {
            if (x.first != 0 && x.second != 2 * n + 1) 
                resp[x.first - 1][x.second - n - 1] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (resp[i][j] ? 'X' : '.');
            }
            cout << '\n';
        }
    }
    return 0;
}