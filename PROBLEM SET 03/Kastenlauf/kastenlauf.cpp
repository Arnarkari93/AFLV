#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

struct store
{
    int x;
    int y;
    
    store(int x, int y) {
        
        this->x = x;
        this->y = y;
    }
    
    void print(){
        cout << x << " " << y << endl;
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

int count_distance(store a, store b);

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    
    int t, n;
    cin >> t;
    
    for (int i = 0; i < t; ++i){
        
        cin >> n;
        vector<store> vec;
        
        for (int j = 0; j < n + 2; ++j) {
            
            int x, y;
            cin >> x >> y;
            
            store s(x, y);
            vec.push_back(s);
        }
        union_find uf(n+2);
        
        for (unsigned int i = 0; i < vec.size(); ++i) {
            
            for (unsigned int j = 0; j < vec.size(); ++j) {
                
                if (i != j) {
                    
                    if (count_distance(vec[i], vec[j]) <= 1000){
                    
                        uf.unite(i, j);
                    }
                }
            }
        }
        
        int a = uf.find(0);
        int b = uf.find(n+1);
        
        if (a == b) {
            
            cout << "happy" << endl;
            
        } else {
            cout << "sad" << endl;
        }
    }
    return 0;
}

int count_distance(store a, store b)
{
    int x = abs(a.x - b.x);
    int y = abs(a.y - b.y);
    return x + y;
}