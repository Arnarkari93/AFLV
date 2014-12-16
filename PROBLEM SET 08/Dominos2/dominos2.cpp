#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

vector<int> adj[10000];
bool visited[10000];

void dfs(int u) 
{
	if (visited[u]) {
		return; 
	}
	
	visited[u] = true;

	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		dfs(v);
	} 
}

int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

	int ts;
	cin >> ts;
	int n, m, l;
	for (int t = 0; t < ts; ++t)
	{
		int counter = 0;

		cin >> n >> m >> l;
		int x, y;
		for (int i = 0; i < m; ++i)
		{
			cin >> x >> y;
			adj[x - 1].push_back(y - 1);
		}

		for (int i = 0; i < l; ++i)
		{
			int pused;
			cin >> pused;
			dfs(pused - 1);
		}

		for (int i = 0; i < 10000; ++i)
		{
			if (visited[i]) {
				counter++;
			}
			adj[i].clear();
			visited[i] = false;
		}

		cout << counter << endl;
	}	
	return 0;
}