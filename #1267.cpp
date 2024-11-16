/*
BackJoon No.
#1267
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n;
	
	int y = 0;
	int m = 0;
	for(int i=0; i<n; ++i){
		double tmp;
		cin >> tmp;

		y += (int(tmp / 30) + 1) * 10;
		m += (int(tmp / 60) + 1) * 15;
	}

	if(y == m){
		cout << "Y M " << y;
	}else if(y < m){
		cout << "Y " << y;
	}else{
		cout << "M " << m;
	}

	return 0;
}