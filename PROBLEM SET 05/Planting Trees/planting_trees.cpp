#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; ++i)
	{
		int days;
		cin >> days;
		v.push_back(days);
	}

	sort(v.begin(), v.end(), greater<int>());

	int max = v[0];
	for (size_t i = 0; i < v.size(); ++i)
	{
		if ((v[i] + i + 1) > max)
		{
			max = v[i] + i + 1;
		}
	}
	cout << max + 1 << endl;

	return 0;
}

/*
4
2 3 4 3
*/