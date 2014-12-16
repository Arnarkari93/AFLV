#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

vector<int> adj[100100];
vector<int> side(100100, -1);
bool is_bipartite = true;

void check_bipartite(int u) 
{
	for (int i = 0; i < adj[u].size(); i++) 
	{
		int v = adj[u][i];
		if (side[v] == -1) {
			side[v] = 1 - side[u];
			check_bipartite(v);
		} else if (side[u] == side[v]) {
			is_bipartite = false;
		}
	}	 
}

int main() 
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    
	int n;
	cin >> n;

	map<string, int> items;
	for (int i = 0; i < n; i++) 
	{
		string item;
		cin >> item;
		items[item] = i;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		string a, b;
		cin >> a >> b;
		adj[ items[a] ].push_back( items[b] );
		adj[ items[b] ].push_back( items[a] );
	}

	for (int i = 0; i < n; i++)
	{
		check_bipartite(i);
	}

	if(!is_bipartite) {

		cout << "impossible" << endl;

	} else {

		for(map<string,int>::iterator it = items.begin(); it != items.end(); it++)
		{
			if (side[ it->second ] == -1) {
				cout << it->first << " ";
			}
		}
		cout << endl;
		for(map<string,int>::iterator it = items.begin(); it != items.end(); it++)
		{
			if (side[ it->second ] != -1) {
				cout << it->first << " ";
			}
		}
		cout << endl;
	}

	return 0;
}


     
