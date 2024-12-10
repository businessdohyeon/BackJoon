/*
BackJoon No.
#32929
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	unsigned int n;
	cin >> n;

	switch((n-1)%3){
		case 0:
			cout << "U";
			break;
		case 1:
			cout << "O";
			break;
		case 2:
			cout << "S";
			break;
		default:
			break;
	}

	return 0;
}