#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

vector<int> adj[1005000];
bool visited[1005000];
int coast = 0;

void dfs(int u, bool *is_land) 
{
	if (is_land[u]) {
    	coast++;
    	return;
    }

    if (visited[u]) {
        return; 
    }
    visited[u] = true;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs(v, is_land);
    } 
}

int main()
{
	int m, n;
	cin >> n >> m;
	int map_size = (n + 2) * (m + 2);
	bool is_land[map_size];

	// initialize as false
	memset(is_land, 0, map_size);
	memset(visited, 0, sizeof(visited));

	// initialize map 
	int index = (m + 2) + 1;

	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char c;
			cin >> c;
			c == '1' ? is_land[index] = true : is_land[index] = false;
			index++;
		}
		index += 2;
	}

	// conect the map 
	for (int i = 0; i < map_size; ++i)
	{
		if(!is_land[i])
		{
			if( (i % (m + 2) != 0) ) { // check left

				adj[i].push_back(i - 1);
			}

			if( (i - (m + 2) >= 0) ) { //check up

				adj[i].push_back(i - (m + 2));
			}

			if( (i % (m + 2) != (m + 1)) ) { // check right

				adj[i].push_back(i + 1);
			}

			if( (i + (m + 2) < map_size) ) { // check down

				adj[i].push_back(i + (m + 2));
			}
		}
	}

	dfs(0, is_land);
	cout << coast << endl;

	return 0;
}
