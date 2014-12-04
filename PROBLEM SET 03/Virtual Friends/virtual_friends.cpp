#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

struct person
{
	string name;
	vector<person> friends;

	void add_friend(person p){
		friends.push_back(p);
	}
};

struct social_network
{
	vector<person> peoples;

	social_network(){
		nrOf_peoples = 0;
	}

	void add_people(person p){
		nrOf_peoples++;
		peoples.push_back(p);
	}

	void make_friends(person p1, person p2){

		p1.add_friend(p2);
		p2.add_friend(p1);
	}	



};


int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int t, F;
	cin >> t; 

	for (int i = 0; i < t; ++i)
	{
		cin >> F;

		for (int j = 0; j < F; ++j)
		{
			string p1, p2;
			cin >> p1 >> p2;


		}
	}
	return 0;
}