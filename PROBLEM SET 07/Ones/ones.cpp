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


int get_next_numer(int num, int n);

int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    
	int n = 0;
	cin >> n;
	while(!cin.eof())
	{
		int result = 1;
		int counter = 1;
		while( result % n != 0)
		{
			result = get_next_numer(result, n);
			counter++;
		}
		cout << counter << endl;
		cin >> n;
	}
	return 0;
}

int get_next_numer(int num, int n)
{
	return ((num * 10) + 1) % n;
}