/*
BackJoon No.
#32710
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for(int i=2; i<=9; ++i){
		for(int j=1; j<=9; ++j){
			if(n == i || n == j || n == i*j){
				cout << 1;
				return 0;
			}
		}
	}

	cout << 0;

	return 0;
}