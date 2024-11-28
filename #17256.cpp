/*
BackJoon No.
#17256
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int ax, ay, az;
	int cx, cy, cz;

	cin >> ax >> ay >> az;
	cin >> cx >> cy >> cz;

	// cx = az+bx
	int bx = cx - az;

	// cy = ay*by;
	int by = cy / ay;

	// cz = ax+bz
	int bz = cz - ax;

	cout << bx << ' ' << by << ' ' << bz;

	return 0;
}