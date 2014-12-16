#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;


int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
	int n, m;
	cin >> n;
	while(!cin.eof()) {
		
		cin >> m;

		bool *win_state = new bool [n + 1];
		memset(win_state, false, n+1);

		win_state[1] = true; // who takes the last stone wins

		int *legal_moves = new int[m];
		int mov;

		for (int i = 0; i < m; ++i)
		{
			cin >> mov;
			legal_moves[i] = mov;
			win_state[mov] = true; 
		}

		for (int i = 0; i < n + 1; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int l = legal_moves[j];
				
				// if the current state points to a lose state
				if (i - l >= 0 && !win_state[i - l]) { 
					win_state[i] = true;
				}	
			}
			// stones_left[i] ? printf("%d Win\n", i) : printf("%d Lose\n", i);
		}

		if (win_state[n]) {
			cout << "Stan wins" << endl;
		} else {
			cout << "Ollie wins" << endl;
		}

		delete []win_state;
		delete []legal_moves;

		cin >> n;
	}
	return 0;
}