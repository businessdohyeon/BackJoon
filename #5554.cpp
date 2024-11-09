/*
BackJoon No.
#5554
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int total = 0;
	for(int i=0; i<4; ++i){
		int tmp;
		cin >> tmp;
		total += tmp;
	}

	cout << total / 60 << '\n' << total % 60;

	return 0;
}