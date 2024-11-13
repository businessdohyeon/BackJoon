/*
BackJoon No.
#5575
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	for(int i=0; i<3; ++i){
		int hr, min, sec;

		cin >> hr >> min >> sec;
		int enter = hr*60*60 + min*60 + sec;

		cin >> hr >> min >> sec;
		int exit = hr*60*60 + min*60 + sec;

		int gap = exit - enter;
		cout << gap/60/60 << ' ' << gap/60%60 << ' ' << gap%60 << '\n';
	}

	return 0;
}