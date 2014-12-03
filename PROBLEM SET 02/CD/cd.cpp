#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

int main()
{

	int n, m; 
	cin >> n >> m;
	while (n != 0 || m != 0) {
		
		queue<int> jack;
		queue<int> jill;

		for (int i = 0; i < n; ++i) {
			
			int cd;
			cin >> cd;
			jack.push(cd);
		
		}

		for (int i = 0; i < m; ++i) {
			
			int jill_cd;
			cin >> jill_cd;
			jill.push(jill_cd);

		}

		int mutualCDs = 0;

		while(!jack.empty() && !jill.empty()) {

			int jack_cd = jack.front();
			int jill_cd = jill.front();

			if (jack_cd == jill_cd) { 
			
				mutualCDs++;
				jack.pop();
				jill.pop();
			
			} else if (jack_cd < jill_cd) {
			
				jack.pop();
				
			} else {

				jill.pop();
			}
		}
		cout << mutualCDs << endl;
		cin >> n >> m;
	}
	return 0;
}

