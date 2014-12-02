#include <iostream>
#include <cstdlib>
using namespace std;

void add_space(string &result);
void add_numbers(string &result, string keys[], char curr);

int main()
{
	string keys[12] = {
		"",		"abc",	"def",
		"ghi", 	"jkl",	"mno",
		"pqrs", "tuv",	"wxyz",
		"",		" ",	""
	};

	int test_cases;
	cin >> test_cases;
	cin.ignore();
	for (int i = 0; i < test_cases; ++i)
	{
		string sms;
		getline(cin, sms);
		string result = "";
		for (int j = 0; j < sms.length(); ++j)
		{
			char curr = sms[j];
			if (curr == ' ') {
				add_space(result);
			} else {
				add_numbers(result, keys, curr);
			}
		}
		cout << "Case #" <<  i + 1 << ": " << result << endl;
	}
	return 0;
}

void add_space(string &result) 
{
	if(result.back() == '0') {
		result.append(" ");
	}
	result.append("0");
}

void add_numbers(string &result, string keys[], char curr)
{
	for (int i = 0; i < 12; ++i)
	{
		int accur = keys[i].find(curr) + 1;
		if (accur >= 1) {
			if((int)result.back() - 48 == i + 1) { // if we are entering the same number as before
				result.append(" ");
			}
			for (int j = 0; j < accur; ++j) {
				result.append(to_string(i + 1));
			}
		}
	}
}