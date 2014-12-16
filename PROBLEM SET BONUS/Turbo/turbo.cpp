#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int size;
	cin >> size;
	list<int> mylist;
	int num = 0;
	bool front = true;

	int begin = 1;
	int end = size;

	for (int t = 0; t < size; ++t)
	{	
		cin >> num;
		mylist.push_back(num);
	}
	
	for (int i = 0; i < size; ++i)
	{
		if (front) {
			
			while(*it != begin) {

			}

		} else {

		}
	}






	for (list<int>::iterator it = mylist.begin();  it != mylist.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}