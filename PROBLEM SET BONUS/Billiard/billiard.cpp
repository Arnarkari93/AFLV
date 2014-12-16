#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>	
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

	double a, b, s, m, n;
	cin >> a >> b >> s >> m >> n;
	while (a != 0 && b != 0 && s != 0 && m != 0 && n != 0){

		double PI = (atan(1) * 4),
			   angle = atan( (b / a) * (n / m) ) * 180 / PI;

		double hor = a * m,
			   ver = b * n,
			   dist = sqrt((hor * hor) + (ver * ver));

		cout << fixed << showpoint << setprecision(2);
		cout << angle << " " << dist / s << endl;

		cin >> a >> b >> s >> m >> n;
	}
	return 0;
}