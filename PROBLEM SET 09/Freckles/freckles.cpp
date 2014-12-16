#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

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


struct edge {
	double u, v;
	double weight;
	edge(double _u, double _v, double _w) {
		u = _u;  
		v = _v;
		weight = _w;
	} 
};

struct union_find {
    
    vector<int> parent;
    
    union_find(int n) {
        
        parent = vector<int>(n);
        
        for (int i = 0; i < n; i++) {
            
            parent[i] = i;
        }
    }
    // find and union
    int find(int x) {
        
        if (parent[x] == x) {
            
            return x;
            
        } else {
            
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    
    void unite(int x, int y) {
        
        parent[find(x)] = find(y);
    }
};

bool edge_cmp(const edge &a, const edge &b) {
	return a.weight < b.weight;
}

vector<edge> mst(int n, vector<edge> edges) 
{
	union_find uf(n);
	sort(edges.begin(), edges.end(), edge_cmp);
	vector<edge> res;
	for (int i = 0; i < edges.size(); i++) 
	{
		int u = edges[i].u,
		v = edges[i].v;
		if (uf.find(u) != uf.find(v)) {
			uf.unite(u, v);
			res.push_back(edges[i]);
		}
	}
	return res; 
}

int main()
{
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; ++t)
	{
		int n;
		cin >> n;
		vector<Point> freckles;
		vector<edge> adj;
		for (int i = 0; i < n; ++i)
		{
			double x, y;
			cin >> x >> y;
			freckles.push_back(Point(x,y));
		}

		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				double dist = freckles[i].distance_to(freckles[j]);
				adj.push_back(edge(i, j, dist));
			}
		}

		vector<edge> mstree = mst(n, adj);
		double sum = 0;
		for (int i = 0; i < mstree.size(); ++i)
		{
			sum += mstree[i].weight;
		}
		cout << setprecision(2) << fixed << showpoint << sum << endl;
	}
	return 0;
}