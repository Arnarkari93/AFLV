#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int t, n;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		cin >> n;
		vector<string> vec;
		string phoneNr;
		
		for (int j = 0; j < n; ++j) {
		
			cin >> phoneNr;
			vec.push_back(phoneNr);
		}

		sort(vec.begin(), vec.end());

		bool is_consistent = true;
		for (size_t k = 0; k < vec.size() - 1; ++k)	{
		
			if (vec[k + 1].substr(0, vec[k].size()) == vec[k]) {
				is_consistent = false;
			}
		}

		if (is_consistent) {
		
			cout << "YES" << endl;
		
		} else {
		
			cout << "NO" << endl;
		}
	}

	return 0;
}

/*
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346

*/