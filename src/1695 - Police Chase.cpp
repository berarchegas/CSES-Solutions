/*
Problem Name: Police Chase
Problem Link: https://cses.fi/problemset/task/1695
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
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
int vis[505];
vector<vector<int>> residualGraph;
 
// Finds if more flow can be sent from source to sink.
// Also assigns levels to nodes.
bool bfs(vector<vector<int>>& residualGraph, vector<int>& level, int source, int sink)
{
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
				// Level of current vertex is level of parent + 1
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
	// IF we can not reach to the sink we
	// return false else true
	return level[sink] < 0 ? false : true ;
}
 
// A DFS based function to send flow after BFS has figured out that there is a possible flow and
// constructed levels. This function called multiple times for a single call of BFS.
// flow : Current flow send by parent function call
// count[] : count of edges explored from i.
// u : Current vertex
int sendFlow(vector<vector<int>>& residualGraph, vector<int>& level, vector<int>& count, int u, int sink, int flow)
{
	// Sink reached
	if (u == sink)
		return flow;
 
    if (count[u] == (int)residualGraph[u].size())
	    return 0;
 
	// Traverse all adjacent edges one-by-one.
	for (int v=0; v < n; v++)
	{
		if (residualGraph[u][v] > 0)
		{
		    count[u]++;
			if (level[v] == level[u]+1)
			{
                // find minimum flow from u to sink
			 	int curr_flow = min(flow, residualGraph[u][v]);
 
			    int min_cap = sendFlow(residualGraph, level, count, v, sink, curr_flow);
			    if (min_cap > 0)
			    {
                    residualGraph[u][v] -= min_cap;
                    residualGraph[v][u] += min_cap;
				    return min_cap;
			    }
			}
		}
	}
	return 0;
}
 
int dinic_algorithm(vector<vector<int>>& graph, int source, int sink)
{
	if (source == sink)
		return -1;
 
	int max_flow = 0;
    residualGraph = graph;
    vector<int> level(n, -1);
 
	// Augment the flow while there is path from source to sink
	while (bfs(residualGraph, level, source, sink) == true)
	{
		// store how many neighbors are visited
		vector<int> count(n, 0);
 
		// while flow is not zero in graph from source to sink
		while (int flow = sendFlow(residualGraph, level, count, source, sink, INT_MAX))
			max_flow += flow;
	}
	return max_flow;
}
 
void addEdge(vector<vector<int>>& graph,
             int u, int v, int w)
{
    graph[u][v] = w;
	graph[v][u] = w;
}
 
int main() {
	int m;
	cin >> n >> m;
    vector<vector<int>> graph(n, vector<int> (n, 0));
	vector<pii> edg;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		addEdge(graph, a, b, 1);
		edg.pb({a, b});
	}
	cout << dinic_algorithm(graph, 0, n-1) << '\n';
	memset(vis, -1, sizeof(vis));
	vis[0] = 1;
	queue<int> fila;
	fila.push(0);
	while (!fila.empty()) {
		int atual = fila.front();
		fila.pop();
		for (int i = 1; i < n; i++) {
			if (vis[i] == -1 && residualGraph[atual][i] > 0) {
				vis[i] = 1;
				fila.push(i);
			}
		}
	}
	for (pii x : edg) {
		if (vis[x.F] == 1 &&  vis[x.S] == -1) cout << x.F+1 << ' ' << x.S+1 << '\n';
		else if (vis[x.S] == 1 && vis[x.F] == -1) cout << x.S+1 << ' ' << x.F+1 << '\n';
	}
	return 0;
}