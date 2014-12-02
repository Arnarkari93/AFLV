#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int count_if_rule_one(string seats, bool isUp);
int count_if_rule_two(string seats, bool isUp);
int count_if_rule_three(string seats, bool isUp);

int main()
{
	bool isUp;
	string seats;
	cin >> seats;

	seats[0] == 'U' ? isUp = true : isUp = false;

	cout << count_if_rule_one(seats.substr(1), isUp) 	 << endl;
	cout << count_if_rule_two(seats.substr(1), isUp) 	 << endl;
	cout << count_if_rule_three(seats.substr(1), isUp) << endl;
	return 0;
}

int count_if_rule_one(string seats, bool isUp)
{
	int count = 0;
	if (isUp) {
		for (int i = 0; i < seats.length(); ++i) {
			if(seats[i] == 'D') {
				count = count + 2;
			}
		}
	} else {
		count++;
		for (int i = 1; i < seats.length(); ++i) {
			if(seats[i] == 'D') {
				count = count + 2;
			} 
		}
	}
	return count;
}
int count_if_rule_two(string seats, bool isUp)
{
	int count = 0;
	if (isUp) {
		count++;
		for (int i = 1; i < seats.length(); ++i) {
			if (seats[i] == 'U') {
				count = count + 2;
			}
		}
	} else {
		for (int i = 0; i < seats.length(); ++i) {
			if (seats[i] == 'U') {
				count = count + 2;
			}
		}
	}
	return count;
}
int count_if_rule_three(string seats, bool isUp)
{
	int count = 0;
	for (int i = 0; i < seats.length(); ++i) {
		if(seats[i] == 'U' && !isUp) {
			count++;
			isUp = !isUp;
		} else if (seats[i] == 'D' && isUp) {
			count++;
			isUp = !isUp;
		}
	}
	return count;
}