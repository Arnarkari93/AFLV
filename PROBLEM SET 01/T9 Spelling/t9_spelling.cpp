#include <iostream>
#include <cstdlib>
using namespace std;

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
				if(result.back() == '0') {
					result.append(" ");
				}
				result.append("0");
			} else {
				for (int k = 0; k < 12; ++k)
				{
					int index = keys[k].find(curr);
					if (index != -1) {
						index++;
						if((int)result.back() - 48 == k + 1) {
							result.append(" ");
						}
						for (int l = 0; l < index; ++l) {
							result.append(to_string(k + 1));
						}
					}
				}
			}
		}
		cout << "Case #" <<  i + 1 << ": " << result << endl;
	}
	return 0;
}