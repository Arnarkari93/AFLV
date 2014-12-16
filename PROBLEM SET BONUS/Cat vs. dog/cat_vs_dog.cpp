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

struct voter
{
	string a;
	string b;
	voter(string up, string down){
		a = up;
		b = down;
	}
};

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; ++t)
	{
		int c, d, v;
		cin >> c >> d >> v;
		vector<voter> voters;

		int SOURCE = 0,
	    	SINK = SOURCE + 1,
	    	LEFT = SINK + 1,  
	    	RIGHT = LEFT + v, 
	    	CNT = RIGHT + v; 

		flow_network g(CNT);
		for (int i = 0; i < v; ++i)
		{
			string vote1, vote2;
			cin >> vote1 >> vote2;
			voters.push_back(voter(vote1, vote2));
			g.add_edge(SOURCE, (LEFT + i), 1);
			g.add_edge((RIGHT + i), SINK, 1);
		}

		for (int i = 0; i < voters.size(); ++i)
		{
			for (int j = 0; j < voters.size(); ++j)
			{
                if((voters[i].a == voters[j].b || voters[i].b == voters[j].a))
				{
					g.add_edge(LEFT + i, RIGHT + j, 1);
				}
			}
		}
		int mxflow = g.max_flow(SOURCE, SINK);

		cout << v - (mxflow / 2) << endl;
	}

	return 0;
}