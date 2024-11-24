/*
BackJoon No.
#20499
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int k, d, a;
	char tmp;
	cin >> k >> tmp >> d >> tmp >> a;
	if(k+a < d || d == 0){
		cout << "hasu";
	}else{
		cout << "gosu";
	}

	return 0;
}