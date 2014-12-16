#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
	long double n;
	int i = 1;
	cin >> n;
	while (!cin.eof())
	{
		long double triangles = pow(3,n);
		long double edge = pow(0.5, n);
		long double result = floor( log10l( triangles * (edge * 3) ) ) + 1;
		cout << "Case " << i << ": " << result << endl;
		i++;
		cin >> n;
	}
	return 0;
}