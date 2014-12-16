#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[100000];
vector<bool> visited_dfs(100000, false);
vector<bool> visited_ts(100000, false);
vector<int> order;


void dfs(int u) 
{
    if (visited_dfs[u]) {
        return; 
    }
    visited_dfs[u] = true;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs(v);
    } 
}

void topsort(int u) 
{
    if (visited_ts[u]) {
        return; 
    }
    visited_ts[u] = true;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        topsort(v);
    }
    order.push_back(u);
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; ++t)
    {

        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;
            adj[x - 1].push_back(y - 1);
        }
        
        for (int i = 0; i < n; ++i)
        {
            topsort(i);
        }
        reverse(order.begin(), order.end());

        int counter = 0;
        for (int i = 0; i < order.size(); ++i)
        {
            if(!visited_dfs[order[i]]) {
                dfs(order[i]);
                counter++;
            }
        }    
        cout << counter << endl;    

        for (int i = 0; i < 100000; ++i)
        {
            adj[i].clear();
            visited_dfs[i] = false;
            visited_ts[i] = false;
        }
        order.clear();
    }

	return 0;
}