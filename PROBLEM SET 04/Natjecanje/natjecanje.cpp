#include <iostream>
#include <cstdlib>
#include <list>
#include <algorithm>
using namespace std;
bool is_next_to (int team1, int team2);
int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

	int N, S, R;

	cin >> N >> S >> R;

	int count = 0;

	int team;
	list<int> damaged;
	list<int> extra;
	for (int i = 0; i < S; ++i) {
		
		cin >> team;
		damaged.push_back(team);
	}

	for (int i = 0; i < R; ++i)
	{
		cin >> team;
		extra.push_back(team);
	}

	damaged.sort();
	extra.sort();
	
	while(!damaged.empty() && !extra.empty()) {

		int d_f = damaged.front();
		int r_f = extra.front();

		if (find(damaged.begin(), damaged.end(), r_f) != damaged.end()){

			damaged.remove(r_f);
			extra.remove(r_f);

		} else if ( is_next_to (r_f, d_f)) {

			damaged.remove(d_f);
			extra.remove(r_f);

		} else {

			int d_b = damaged.back();
			if (r_f < d_b) {
				extra.remove(r_f);
			} else {
				damaged.remove(d_f);
			}
		}
	}

	cout << damaged.size() << endl;

	return 0;
}

bool is_next_to (int team1, int team2) 
{
	return((team1 == (team2 - 1)) || (team1 == (team2 + 1)));
}
