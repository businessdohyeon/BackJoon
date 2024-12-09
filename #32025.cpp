/*
BackJoon No.
#32025
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int h, w;
	cin >> h >> w;

	cout << min(h, w) * 100 / 2;

	return 0;
}