/*
BackJoon No.
#10797
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int cnt = 0;
	for(int i=0; i<5; ++i){
		int tmp;
		cin >> tmp;
		if(tmp % 10 == n % 10){
			++cnt;
		}
	}

	cout << cnt;

	return 0;
}