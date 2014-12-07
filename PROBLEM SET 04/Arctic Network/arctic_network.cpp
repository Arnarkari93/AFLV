#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include <algorithm> 
#include <cmath>
#include <vector>
#include <map>
using namespace std;

struct WQU
{
    int *id;
    int *sz;
    int count;
    
    WQU(int n) {
        count = n;
        id = new int[n];
        sz = new int[n];
        for (int i = 0; i < n; ++i) {
            
            id[i] = i;
            sz[i] = 1;
        }
    }
    
    int _count() {
        return count;
    }
    
    int find(int p) {
        
        int root = p;
        
        while (root != id[root]) {
            root = id[root];
        }
        
        while (p != root) {
            
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        
        return root;
    }
    
    int get_size(int p) {
        
        int root = find(p);
        return sz[root];
    }
    
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    
    void _union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) {
            return;
        }
        
        // make smaller root Point to larger one
        if   (sz[rootP] < sz[rootQ]) {
            
            id[rootP] = rootQ;
            sz[rootQ] += sz[rootP];
            
        } else {
            
            id[rootQ] = rootP;
            sz[rootP] += sz[rootQ];
        }
        
        count--;
    }
};

struct Point
{	
	int x;
	int y;

	Point() 
	{
		x = 0;
		y = 0;
	}

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	double distance_to(Point that)
	{
		double x = static_cast<double>(this->x - that.x);
		double y = static_cast<double>(this->y - that.y);
		return sqrt(( x * x ) + ( y * y ));
	}
};

struct Edge
{	
	int from, to;
	double dist;

	Edge(int from, int to, double dist) 
	{
		this->from = from;
		this->to = to;
		this->dist = dist;
	}
};

inline std::ostream& operator << (std::ostream& stream, const Point& p) {
    return stream << p.x << "," << p.y;
}

void print_edges(vector<Edge> edges);

int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

	int ts;
	cin >> ts;	

	for (int t = 0; t < ts; ++t) 
	{	
		int S, P;
		cin >> S >> P;
		
		vector<Edge> edges;
		vector<Point> outposts;

		for (int i = 0; i < P; ++i) 
		{
			int x, y;
			cin >> x >> y;
			outposts.push_back( Point(x,y) );
		}
		
		for (int i = 0; i < outposts.size() - 1; ++i)
		{
			for (int j = i + 1; j < outposts.size(); ++j)
			{
				double dist = outposts[i].distance_to(outposts[j]);
				edges.push_back(Edge(i, j, dist));
				//cout << "i: " << outposts[i] << " j: " << outposts[j] << " ==> " <<  dist << endl;
			}
		}

		double EPS = 1e-10, lo = 0.0, hi = 15000.0;
		while (hi - lo > EPS) 
		{
			WQU wqu(P);

			double mid = (lo + hi) / 2.0;
			int i = 0;
			for(vector<Edge>::iterator it = edges.begin(); it != edges.end(); ++it) 
			{
				if(it->dist <= mid)
				{
					wqu._union(edges[i].from, edges[i].to);
				}
				i++;
			}

			if (wqu.count > S) 
			{
				lo = mid;
			} 
			else 
			{
				hi = mid;
			} 
		}
		cout << fixed << showpoint << setprecision(2) << hi << endl;
		// print_edges(edges);
	}

	return 0;
}

void print_edges(vector<Edge> edges)
{
	for(vector<Edge>::iterator it = edges.begin(); it != edges.end(); ++it) 
		{
			cout << "From: "<<  it->from << " To:" << it->to << " -> Dist:" <<  it->dist << endl;
		}
}