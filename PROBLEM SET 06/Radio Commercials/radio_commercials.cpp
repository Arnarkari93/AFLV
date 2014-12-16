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

int arr[100000];
int mem[100000];
bool comp[100000];

int max_sum(int i);

int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    
	int N, P;
	cin >> N >> P;
	memset(arr, 0, sizeof(arr));
	memset(mem, 0, sizeof(mem));
	memset(comp, 0, sizeof(comp));

	int maximum = 0;
	for (int i = 0; i < N; ++i)
	{
		int val;
		cin >> val;
		arr[i] = val - P;
		maximum = max(maximum, max_sum(i));
	}	

   	cout << maximum << endl;
	return 0;
}

int max_sum(int i) 
{
	if (i == 0) 
	{
		return arr[i];
	}
	if (comp[i]) 
	{
		return mem[i];
	}

	int res = max(arr[i], arr[i] + max_sum(i - 1));

	mem[i] = res;
	comp[i] = true;
	return res;
}