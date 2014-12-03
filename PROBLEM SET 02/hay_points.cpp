#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;

int main()
{
	int m, n;
	cin >> n >> m;
	map<string, int> dictionary;

	for (int i = 0; i < n; ++i) {
		string word;
		int value;
		cin >> word >> value;
		dictionary[word] = value;
	}

	for (int j = 0; j < m; ++j) {
		int salary = 0;
		string curr; 
		cin >> curr;

		map<string, int>::iterator it;

		while(curr != ".") {
			it = dictionary.find(curr);
			if (it != dictionary.end()){
				salary += dictionary.find(curr)->second;
			}
			cin >> curr;
		}

		cout << salary << endl;
	}
	
	return 0;
}

/*
7 2
administer 100000
spending 200000
manage 50000
responsibility 25000
expertise 100
skill 50
money 75000
the incumbent will administer the spending of kindergarden milk money
and exercise responsibility for making change he or she will share
responsibility for the task of managing the money with the assistant
whose skill and expertise shall ensure the successful spending exercise
.
this individual must have the skill to perform a heart transplant and
expertise in rocket science
.

*/