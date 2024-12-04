/*
BackJoon No.
#11948
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a[4], b[2];
	int aTotal = 0;
	int bTotal = 0;

	for(int i=0; i<4; ++i){
		cin >> a[i];
		aTotal += a[i];
	}
	for(int i=0; i<2; ++i){
		cin >> b[i];
		bTotal += b[i];
	}

	int ans = 0;
	for(int i=0; i<4; ++i){
		for(int j=0; j<2; ++j){
			int tmp = aTotal + bTotal;
			tmp -= a[i];
			tmp -= b[j];
			ans = max(ans, tmp);
		}
	}

	cout << ans;

	return 0;
}