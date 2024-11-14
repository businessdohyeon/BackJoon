/*
BackJoon No.
#10039
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int total = 0;
	for(int i=0; i<5; ++i){
		int tmp;
		cin >> tmp;

		if(tmp < 40)	tmp = 40;
		total += tmp;
	}

	cout << total / 5;

	return 0;
}