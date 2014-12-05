#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

	int N, S, R;

	cin >> N >> S >> R;
	bool d[N]; // who has damaged boat
	bool e[N]; // who has extra boad

	for (int i = 0; i < N; ++i) {
		d[i] = false;
		e[i] = false;
	}
	
	int team;
	for (int i = 0; i < S; ++i) {
		
		cin >> team;
		team--;
		d[team] = true;
	}

	for (int i = 0; i < R; ++i) {
		cin >> team;
		team--;
		e[team] = true;
	}

	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		if( d[i] && e[i] ) { // damaged kayak and has extra
			
			d[i] = false;
			e[i] = false;  

 		} else if (!d[i]) { // kayak ok

 			continue;  

 		} else { // has damaged kayak and dosen't hava an extra 

			if ( i == 0) { // team 1

				if ( e[i + 1] && !d[i + 1] ) { // team 2 has an extra kayak to spare

					d[i] = false;
					e[i + 1] = false;

				} else {

					count++;
				}

			} else if ( i == N - 1 ) { // team N

				if ( e[i - 1] && !d[i - 1] ) { // team N - 1 has an extra kayak to spare

					d[i] = false;
					e[i - 1] = false;
				
				} else {
				
					count++;
				}

			} else {  // 1 < team < N

				if ( e[i - 1] && !d[i - 1] ) { // team to the left has a kayak to spare

					d[i] = false;
					e[i - 1] = false;

				} else if ( e[i + 1] && !d[i + 1] ) {  // team to the right has a kayak to spare

					d[i] = false;
					e[i + 1] = false;

				} else { 

					count++;
				}
			}
		}
	}

	cout << count << endl;

	return 0;
}
