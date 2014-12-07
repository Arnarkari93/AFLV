#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

string reverse(string str);

int main()
{
	string original, infected;

	cin >> original >> infected;

	int index = 0;
	int l_i = infected.length();
	int l_o = original.length();
	for (int i = 0; i < l_i || i < l_o; ++i)
	{
		if(infected[index] == original[index])
		{
			index++;
		}
	}
	//cout << index << endl;

	original = original.substr(index);
	infected = infected.substr(index);

	//cout << "original: " << original << endl;
	//cout << "infected: " << infected << endl;

	original = reverse(original);
	infected = reverse(infected);
	//cout << "reserve original: " << original << endl;
	//cout << "reserve infected: " << infected << endl;

	index = 0;
	l_i = infected.length();
	l_o = original.length();
	for (int i = 0; i < l_i || i < l_o; ++i)
	{
		if(infected[index] == original[index])
		{
			index++;
		}
	}

	cout << infected.substr(index).length() << endl;

	return 0;
}

string reverse(string str)
{
	string result = "";
	for (int i = str.length(); i >= 0 ; i--) 
	{
		result += str[i];
	}
	return result;	 
}
