/*
BackJoon No.
#10768
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int a, b;
	cin >> a >> b;

	if(a == 2 && b == 18){
		cout << "Special";
	}else if(a < 2 || a == 2 && b < 18){
		cout << "Before";
	}else{
		cout << "After";
	}

	return 0;
}