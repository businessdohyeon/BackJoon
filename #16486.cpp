/*
BackJoon No.
#16486
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	double r, w;
	cin >> w >> r;
	cout << setprecision(6) << fixed << 2 * M_PI * r + 2 * w;

	return 0;
}