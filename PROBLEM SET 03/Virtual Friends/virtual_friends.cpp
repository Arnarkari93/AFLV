#include <iostream>
#include <cstdlib>
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
        
        // make smaller root point to larger one
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

void add_person(map<string, int> &map, string name, int &index);

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    
    int t, F;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        
        cin >> F;
        
        WQU wqu(F*2);
        
        map<string, int> map;
        int index = 0;
        
        for (int j = 0; j < F; ++j) {
            
            string p1, p2;
            cin >> p1 >> p2;
            add_person(map, p1, index);
            add_person(map, p2, index);
            
            wqu._union(map[p1], map[p2]);
            
            cout << wqu.get_size(map[p1]) << endl;
        }
    }
    
    return 0;
}

void add_person(map<string, int> &map, string name, int &index) 
{
    if (map.count(name) > 0) {
        
        return;
        
    } else {
        
        map[name] = index;
        index++;
    }
}