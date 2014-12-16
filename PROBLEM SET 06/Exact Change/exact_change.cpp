#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T &x) { return x.size(); }

// assert or gtfo


int INF = 100000;
int d[100];
int mem[100][10000];
bool taken[100][10000];

int opt(int i, int x)
{
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (i == -1) return INF;
    
    if (mem[i][x] != -1) return mem[i][x];
    
    int res = INF;
    
    int a = 1 + opt(i - 1, x - d[i]);
    int b = opt(i - 1, x);
    
    if (a < b) {
        taken[i][x] = true;
    } else {
        taken[i][x] = false;
    }
    
    res = min(a, b);
    
    mem[i][x] = res;
    return res;
}


int find_opt(int i, int x, int sum)
{
    if (x == 0) {
        return sum;
    }

    if (taken[i][x]) {
        sum += d[i];

        return find_opt(i, x - d[i], sum);

    } else {

        return find_opt(i - 1, x, sum);
    }
    return sum;
}


int main()
{
    int ts;
    cin >> ts;
    for (int t = 0; t < ts; ++t)
    {	
    	memset(mem, -1, sizeof(mem));
    	memset(d, 0, sizeof(d));
    	memset(taken, 0, sizeof(taken));

        int price, bills;
        cin >> price >> bills;
        
        for (int i = 0; i < bills; ++i)
        {
            cin >> d[i];   
        }

        int temp = opt(bills - 1, price);
        while (temp == INF) {
        	price++;
            temp = opt(bills - 1, price);
        } 
        cout << find_opt(bills - 1, price, 0) << " " << temp << endl;
    }
    
    return 0;
}

