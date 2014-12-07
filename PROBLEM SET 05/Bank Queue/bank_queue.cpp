#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, T;
	cin >> N >> T;

	vector<pair<int,int> > costumers;

	for (int i = 0; i < N; ++i)
	{
		int money, wait;
		cin >> money >> wait;
		costumers.push_back(pair<int,int> (money, wait));
	}

	sort(costumers.begin(), costumers.end(), greater<pair<int, int> >());

	//cout << "orderd costumers" << endl;
	for (int i = 0; i < costumers.size(); ++i)
	{
		//cout << costumers[i].first << " " << costumers[i].second <<  endl;
	}

	int queue[T];
	for (int i = 0; i < T; ++i)
	{
		queue[i] = 0;
	}


	for (int i = 0; i < N; ++i)
	{
		int test = costumers[i].second;
		while(queue[test]) // 
		{
			test--;
		}
		if (test >= 0 && test < T) {
			queue[test] = costumers[i].first;
			// cout << "queue[" << test << "] : " <<  queue[test] <<  endl;
		}	
	}

	int money_sum = 0;
	for (int i = 0; i < T; ++i)
	{
		money_sum += queue[i];
		//cout << queue[i] << " ";
	}
	cout << money_sum << endl;

	return 0;
}