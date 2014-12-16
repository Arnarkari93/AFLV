#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;


struct edge {
	int u, v;
	double weight;
	edge(int _u, int _v, double _w) {
		u = _u;  
		v = _v;
		weight = _w;
	} 
};

const double ZERO = 0.0;
vector<edge> adj[20000];
vector<double> dist(20000, ZERO);

void dijkstra(int start) 
{
ls
	dist[start] = 1;
	priority_queue<pair<int, int>,
	vector<pair<int, int> >,
	greater<pair<int, int> > > pq;
	pq.push(make_pair(dist[start], start));
	while (!pq.empty()) 
	{
		int u = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[u].size(); i++) 
		{
			int v = adj[u][i].v;
			double w = adj[u][i].weight;

			if (w * dist[u] > dist[v]) 
			{
				dist[v] = w * dist[u];
				pq.push(make_pair(dist[v], v));
			} 
		}
	} 
}

int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    while(n != 0 && m != 0) {
    	
    	for (int i = 0; i < m; ++i)
    	{
    		int x, y;
    		double f;
    		cin >> x >> y >> f;
    		adj[x].push_back(edge(x, y, f));
    		adj[y].push_back(edge(y, x, f));
    	}

    	/*
    	for (int i = 0; i < n; ++i)
    	{
    		cout << "[" << i << "] -> " << endl;
    		for (int j = 0; j < adj[i].size(); ++j)
    		{
    			cout << "\t" << adj[i][j].u << " " << adj[i][j].v << " " << adj[i][j].weight << endl;
    		}
    		cout << endl;
    	}
    	*/

    	dijkstra(0);
    	cout << setprecision(4) << fixed << showpoint << dist[n - 1] << endl;

    	for (int i = 0; i < 20000; ++i)
    	{
    		adj[i].clear();
    	}

    	dist.assign(dist.size(), ZERO);

    	cin >> n >> m;
    }
	return 0;
}