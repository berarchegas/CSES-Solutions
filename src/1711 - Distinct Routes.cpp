/*
Problem Name: Distinct Routes
Problem Link: https://cses.fi/problemset/task/1711
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
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
 
int n;
int vis[505], mat[505][505];
vector<vector<int>> residualGraph;
 
bool bfs(vector<vector<int>>& residualGraph, vector<int>& level, int source, int sink) {
    fill(level.begin(), level.end(), -1);
	level[source] = 0;
	
	queue<int> q;
	q.push(source);
 
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v=0; v < n; v++)
		{
			if (u != v && residualGraph[u][v] > 0 && level[v] < 0)
			{
 
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
	return level[sink] < 0 ? false : true ;
}
 
int sendFlow(vector<vector<int>>& residualGraph, vector<int>& level, vector<int>& count, int u, int sink, int flow) {
	if (u == sink)
		return flow;
 
    if (count[u] == (int)residualGraph[u].size())
	    return 0;
 
	for (int v=0; v < n; v++)
	{
		if (residualGraph[u][v] > 0)
		{
		    count[u]++;
			if (level[v] == level[u]+1)
			{
			 	int curr_flow = min(flow, residualGraph[u][v]);
 
			    int min_cap = sendFlow(residualGraph, level, count, v, sink, curr_flow);
			    if (min_cap > 0)
			    {
                    residualGraph[u][v] -= min_cap;
                    residualGraph[v][u] += min_cap;
					mat[u][v] = -1;
					mat[v][u] = 1;
				    return min_cap;
			    }
			}
		}
	}
	return 0;
}
 
int dinic_algorithm(vector<vector<int>>& graph, int source, int sink) {
	if (source == sink)
		return -1;
 
	int max_flow = 0;
    residualGraph = graph;
    vector<int> level(n, -1);
 
	while (bfs(residualGraph, level, source, sink) == true)
	{
		vector<int> count(n, 0);
 
		while (int flow = sendFlow(residualGraph, level, count, source, sink, INT_MAX))
			max_flow += flow;
	}
	return max_flow;
}
 
void addEdge(vector<vector<int>>& graph, int u, int v, int w) {
    graph[u][v] = w;
}
 
queue<int> pil;
 
void dfs(int node) {
	pil.push(node);
	vis[node] = 1;
	if (node == n-1) return;
	for (int i = n-1; i > 0; i--) {
		if (!vis[i] && mat[node][i] == -1) {
			vis[i] = 1;
			mat[node][i] = 1;
			dfs(i);
			return;
		}
	}
}
 
int main() { _
	int m;
	cin >> n >> m;
    vector<vector<int>> graph(n, vector<int> (n, 0));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		addEdge(graph, a, b, 1);
		mat[a][b] = 1;
	}
	int tot = dinic_algorithm(graph, 0, n-1);
	cout << tot << '\n';
	while (tot--) {
		memset(vis, 0, sizeof(vis));
		dfs(0);
		cout << pil.size() << '\n';
		while (!pil.empty()) {
			cout << pil.front()+1 << ' ';
			pil.pop();
		}
		cout << '\n';
	}
	return 0;
}