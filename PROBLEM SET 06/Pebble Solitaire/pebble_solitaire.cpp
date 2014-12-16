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

const int GAME_SIZE = 23;
int mem[8388608];

bool is_avaible_move(string &game);
int opt(string &game, int mask);
int balls_count(string &game);
int get_mask(string &game);

int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

	int ts;
	cin >> ts;

	memset(mem, -1, sizeof(mem));
	for (int t = 0; t < ts; ++t)
	{
		string game;
		cin >> game;

		int mask = get_mask(game);
		cout << opt(game, mask) << endl;
	}
	return 0;
}

int opt(string &game, int mask)
{

	if(!is_avaible_move(game))
	{
		int balls_left = balls_count(game);
		mem[mask] = balls_left;
		return balls_left;
	}

	if(mem[mask] != -1) 
	{
		return mem[mask];
	}

	int result = 23;
	int left = 23, right = 23;

	for (int i = 0; i < GAME_SIZE - 1; ++i)
	{
		if(game[i] == 'o' && game[i + 1] == 'o') // we can move
		{
			if(i >= 0 && game[i - 1] == '-') // move to the left
			{
				string temp = game;
				temp[i] = '-';
				temp[i - 1] = 'o';
				temp[i + 1] = '-';

				left = opt(temp, get_mask(temp));
			}

			if(i + 2 < GAME_SIZE && game[i + 2] == '-') // move to the right
			{
				string temp = game;
				temp[i] = '-';
				temp[i + 1] = '-';
				temp[i + 2] = 'o';	

				right = opt(temp, get_mask(temp));						
			}
			result = min(result, min(left, right));
		}
	}
	mem[mask] = result;
	return result;
}

int get_mask(string &game)
{
	int mask = 0;
	for (int i = 0; i < GAME_SIZE; ++i)
	{
		if(game[i] == 'o') {
			
			mask |= (1 << i);
		}
	}
	return mask;
}

int balls_count(string &game)
{
	int c = 0;
	for (int i = 0; i < GAME_SIZE; ++i)
	{
		if(game[i] == 'o') {
			c++;
		}
	}
	return c;
}

bool is_avaible_move(string &game)
{
	for (int i = 0; i < GAME_SIZE - 1; ++i)
	{
		if (game[i] == 'o' && game[i + 1] == 'o') {
			return true;
		}
	}
	return false;
}