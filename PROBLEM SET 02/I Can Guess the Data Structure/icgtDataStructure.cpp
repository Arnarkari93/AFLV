#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
#include <string>
using namespace std;

string get_data_structure(string test, string s, string q, string pq);
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int n;
	cin >> n;
	while(!cin.eof()) {

		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		
		string result = "", r_s = "", r_q = "", r_pq = "";

		for (int i = 0; i < n; ++i) {	
			
			int cmd, nr;
			cin >> cmd >> nr;

			if(cmd == 1) {
				
				s.push(nr);
				q.push(nr);
				pq.push(nr);

			} else {
				
				result.append(to_string(nr));

				if(!s.empty()){

					r_s.append(to_string(s.top()));
					s.pop();
				}
				if(!q.empty()){

					r_q.append(to_string(q.front()));
					q.pop();
				}
				if(!pq.empty()){

					r_pq.append(to_string(pq.top()));
					pq.pop();
				}
			}
		}
		cout << get_data_structure(result, r_s, r_q, r_pq) << endl;

		cin >> n;
	}
	return 0;
}

string get_data_structure(string test, string s, string q, string pq) 
{
	if(test != s && test != q && test != pq){
		
		return "impossible";

	} else if (test == s && test != q && test != pq) {

		return "stack";

	} else if (test != s && test == q && test != pq) {

		return "queue";

	} else if (test != s && test != q && test == pq) {

		return "priority queue";

	} else {

		return "not sure";
	}
}