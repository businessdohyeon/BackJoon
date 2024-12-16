/*
BackJoon No.
#32684
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const double s[] = {13, 7, 5, 3, 3, 2};

	double totalA = 72;
	for(int i=0; i<6; ++i){
		double n;
		cin >> n;
		totalA += n * s[i];
	}

	double totalB = 73.5;
	for(int i=0; i<6; ++i){
		double n;
		cin >> n;
		totalB += n * s[i];
	}

	if(totalA > totalB){
		cout << "cocjr0208";
	}else{
		cout << "ekwoo";
	}

	return 0;
}