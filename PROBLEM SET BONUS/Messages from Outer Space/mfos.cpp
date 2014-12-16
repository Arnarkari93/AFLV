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
using namespace std;

// Messages from Outer Space

int* compute_pi(const string &t) {

    int m = t.size();
    int *pi = new int[m + 1];
    if (0 <= m) pi[0] = 0;
    if (1 <= m) pi[1] = 0;
    for (int i = 2; i <= m; i++) {
        for (int j = pi[i - 1]; ; j = pi[j]) {
            if (t[j] == t[i - 1]) {
                pi[i] = j + 1;
                break;
            }
            if (j == 0) {
                pi[i] = 0;
                break;
            }
        }
    }

    return pi;
}

vector<int> string_match(const string &s, const string &t) {

    vector<int> v;
    int n = s.size(),
        m = t.size();

    int *pi = compute_pi(t);

    for (int i = 0, j = 0; i < n; ) {
        if (s[i] == t[j]) {
            i++; j++;
            if (j == m) {
                v.push_back(i - m);
            }
        }
        else if (j > 0) j = pi[j];
        else i++;
    }

    delete[] pi;
    v.push_back(-1);
    return v;
}

struct substring
{
    int start;
    int end;
    substring(int s, int e){
        start = s;
        end = e;
    }
};

bool compare(const substring& a, const substring& b){
    return a.end < b.end;
}
const int MAX = 50000;

int main()
{
	vector<string> dictionary;
	string word;
	while (cin >> word && word != "#") {
		dictionary.push_back(word);
	}

    while(true){
    
        char message[MAX] =  { ' ' };

        int in = 0;
        while(cin >> message[in] && message[in] != '|'){
            if(message[in] == '#'){
                return 0;
            }
            in++;
        }

        if(message[0] == '|'){
            cout << 0 << endl;
        } else {

            vector<substring> v;

            for (int i = 0; i < dictionary.size(); ++i) {
                vector<int> apperances = string_match(message, dictionary[i]);
                for (int j = 0; j < apperances.size(); ++j)
                {
                    int _beg = apperances[j];
                    if (_beg != -1) {
                        int _end = _beg + dictionary[i].length() - 1;
                        v.push_back(substring(_beg, _end));
                    }
                }
            }

            sort(v.begin(), v.end(), compare); 

            int counter = 0;
            vector<substring> v2;
            for (int i = 0; i < v.size(); ++i) {
                if (v2.empty()) {
                    v2.push_back(v[i]);
                    counter++;
                } else {
                    if ( v2[0].end < v[i].start) {
                        counter++;
                        v2[0] = v[i];
                    }
                }
            }
            cout << counter << endl;
        }
    }
	return 0;
}