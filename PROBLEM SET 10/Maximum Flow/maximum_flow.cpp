#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

// Code from lecture. Author: Bjarki Ágúst Guðmundsson
struct flow_network {

    struct edge {
        int u, v, cap;
        edge *rev;
        bool forward;
        edge(int _u, int _v, int _cap, bool forw)
            : u(_u), v(_v), cap(_cap), forward(forw) { }
    };

    int n;
    vector<vector<edge*> > adj;
    flow_network(int _n) : n(_n), adj(_n) { }

    void add_edge(int u, int v, int cap) {
        edge *e = new edge(u, v, cap, true);
        edge *rev = new edge(v, u, 0, false);
        e->rev = rev;
        rev->rev = e;
        adj[u].push_back(e);
        adj[v].push_back(rev);
    }

    int augment(int s, int t) {
        vector<edge* > back(n, NULL);
        queue<int> Q;
        Q.push(s);
        back[s] = (edge*)1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i]->v;
                if (back[v] == NULL && adj[u][i]->cap > 0) {
                    back[v] = adj[u][i];
                    Q.push(v);
                }
            }
        }

        if (back[t] == NULL)
            return 0;

        stack<edge*> S;
        S.push(back[t]);
        int bneck = back[t]->cap;
        while (S.top()->u != s) {
            S.push(back[S.top()->u]);
            bneck = min(bneck, S.top()->cap);
        }

        while (!S.empty()) {
            S.top()->cap -= bneck;
            S.top()->rev->cap += bneck;
            S.pop();
        }

        return bneck;
    }

    int max_flow(int source, int sink) {
        int flow = 0;
        while (true) {
            int f = augment(source, sink);
            if (f == 0) {
                break;
            }

            flow += f;
        }

        return flow;
    }
};

int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	//  n is the numbers of nodes in the graph
	//  m is the number of edges
	//  s is the source and t is the sink (s != t).
	flow_network g(n);

	for (int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g.add_edge(u, v, c);
	}

	cout << n << " " << g.max_flow(s, t) << " ";

	int counter = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < g.adj[i].size(); ++j)
		{
			if (g.adj[i][j]->forward && g.adj[i][j]->rev->cap > 0){
				counter++;
			}
		}	
	}
	cout << counter << endl;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < g.adj[i].size(); ++j)
		{
			if (g.adj[i][j]->forward && g.adj[i][j]->rev->cap > 0){
				cout << g.adj[i][j]->u << " " << g.adj[i][j]->v << " " 
					 << g.adj[i][j]->rev->cap << endl;
			}
		}
		
	}


	return 0;
}