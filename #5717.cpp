/*
BackJoon No.
#5717
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	while(true){
		int a, b;
		cin >> a >> b;

		if(a == 0 && b == 0)	break;

		cout << a+b << '\n';
	}

	return 0;
}