#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <sstream>
using namespace std;

int main()
{
	
	string read_fat, read_protein, read_sugar, read_starch, read_alcolhol;
	string ans;
	
	getline(cin, ans);
	if (ans == "-") {
		getline(cin, ans);
		if (ans == "-") {
			return 0;
		}
	}
	istringstream sin;
	sin.str(ans);
	do 
	{
		double total_calories = 0;
		double total_fat = 0;
		do
		{
			sin >> read_fat >> read_protein >> read_sugar >> read_starch >> read_alcolhol;
			// cout << read_fat << " " << read_protein << " " << read_sugar << " " 
			// 	 << read_starch << " " << read_alcolhol << endl;
			double perc = 100;
			double fat = 0;
			double calories = 0;
			double temp = 0;
			// read fat
			if (read_fat.substr(read_fat.length() - 1) == "g"){
				temp = stod(read_fat.substr(0, read_fat.length() - 1)) * 9;
				fat += temp;
				calories += temp;
			} else if (read_fat.substr(read_fat.length() - 1) == "C") {
				temp = stod(read_fat.substr(0, read_fat.length() - 1)); 
				fat += temp;
				calories += temp;
			} else {
				perc -= stod(read_fat.substr(0, read_fat.length() - 1));
			}

			// read protain
			if (read_protein.substr(read_protein.length() - 1) == "g"){
				temp = stod(read_protein.substr(0, read_protein.length() - 1)) * 4;
				calories += temp;
			} else if (read_protein.substr(read_protein.length() - 1) == "C") {
				temp = stod(read_protein.substr(0, read_protein.length() - 1));
				calories += temp;
			} else {
				perc -= stod(read_protein.substr(0, read_protein.length() - 1));
			}

			// read sugar
			if (read_sugar.substr(read_sugar.length() - 1) == "g"){
				temp = stod(read_sugar.substr(0, read_sugar.length() - 1)) * 4;
				calories += temp;
			} else if (read_sugar.substr(read_sugar.length() - 1) == "C") {
				temp = stod(read_sugar.substr(0, read_sugar.length() - 1));
				calories += temp;
			} else {
				perc -= stod(read_sugar.substr(0, read_sugar.length() - 1));
			}

			// read starch
			if (read_starch.substr(read_starch.length() - 1) == "g"){
				temp = stod(read_starch.substr(0, read_starch.length() - 1)) * 4;
				calories += temp;
			} else if (read_starch.substr(read_starch.length() - 1) == "C") {
				temp = stod(read_starch.substr(0, read_starch.length() - 1));
				calories += temp;
			} else {
				perc -= stod(read_starch.substr(0, read_starch.length() - 1));
			}

			// read alcolhol
			if (read_alcolhol.substr(read_alcolhol.length() - 1) == "g"){
				temp = stod(read_alcolhol.substr(0, read_alcolhol.length() - 1)) * 7;
				calories += temp;
			} else if (read_alcolhol.substr(read_alcolhol.length() - 1) == "C") {
				temp = stod(read_alcolhol.substr(0, read_alcolhol.length() - 1));
				calories += temp;
			} else {
				perc -= stod(read_alcolhol.substr(0, read_alcolhol.length() - 1));
			}

			// cout << "fat: " << fat << endl;
			// cout << "Perc: " << perc << endl;
			// cout << "calories: " << calories << endl;

			calories = (calories / perc);
			if(read_fat.substr(read_fat.length() - 1) == "%"){
				fat = calories * stod(read_fat.substr(0, read_fat.length() - 1));
				// cout << "fat % to C " << fat << endl;
			}
			// cout << "(calories / perc) * 100: " << calories * 100 << endl;
			
			total_calories += calories;
			total_fat += fat;
			getline(cin, ans);
			sin.clear();
			sin.str(ans);

		} while (ans != "-"); // test case over
		// calculate test case
		// cout << "+++++++" << endl;
		cout << round(total_fat/total_calories) << "%" << endl;

		// read next test case  
		getline(cin, ans);
		sin.clear();
		sin.str(ans);

	} while (ans != "-");

	return 0;
}