#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string.h>
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

struct Point {
	double x, y;
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}

	double distance_to(Point that) {
		double x = this->x - that.x;
		double y = this->y - that.y;
		return sqrt(( x * x ) + ( y * y ));
	}
};

int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

	int n = 0, m = 0, s = 0, v = 0;
	cin >> n;
	while(!cin.eof()){
		cin >> m >> s >> v;

		int SOURCE = 0,
	        SINK = SOURCE + 1,
	        GOPHER = SINK + 1,
	        HOLE = GOPHER + n,
	        CNT = HOLE + m;

		double x, y;

		flow_network g(CNT);

		vector<Point> gophers;
		for (int i = 0; i < n; i++) // input gopher
		{
			cin >> x >> y;
			gophers.push_back(Point(x,y));
			g.add_edge(0, GOPHER + i, 1);
		}
		
		vector<Point> holes;
		for (int i = 0; i < m; i++) // input holes
		{
			cin >> x >> y;
			holes.push_back(Point(x,y));
			g.add_edge(HOLE + i, SINK, 1);
		}

		
		for (int i = 0; i < gophers.size(); i++)
		{
			for (int j = 0; j < holes.size(); j++)
			{
				double dist = gophers[i].distance_to(holes[j]);
				if (dist <= static_cast<double>(s * v)) {
					g.add_edge((GOPHER + i), (HOLE + j), 1);
				}
			}
		}
		cout << n - g.max_flow(SOURCE, SINK) << endl;
		
		cin >> n;
	}
	return 0;
}