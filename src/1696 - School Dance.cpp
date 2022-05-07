/*
Problem Name: School Dance
Problem Link: https://cses.fi/problemset/task/1696
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
 
int main() { _
	int x, y, m;
	cin >> x >> y >> m;
	n = x+y+2;
    vector<vector<int>> graph(n, vector<int> (n, 0));
	vector<pii> edg;
	for (int i = 1; i <= x; i++) addEdge(graph, 0, i, 1);
	for (int i = x+1; i <= x+y; i++) addEdge(graph, i, n-1, 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		addEdge(graph, a, b+x, 1);
		edg.pb({a, b+x});
	}
	cout << dinic_algorithm(graph, 0, n-1) << '\n';
	for (pii a : edg)
		if (!residualGraph[a.F][a.S]) cout << a.F << ' ' << a.S-x << '\n';
	return 0;
}