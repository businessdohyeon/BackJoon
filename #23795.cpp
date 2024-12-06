/*
BackJoon No.
#23795
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int result = 0;
	while(true){
		int n;
		cin >> n;

		if(n == -1)		break;

		result += n;
	}

	cout << result;

	return 0;
}