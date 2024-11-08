/*
BackJoon No.
#5543
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int burger[3];
	int drink[2];
	for(int i=0; i<3; ++i){
		cin >> burger[i];
	}
	for(int i=0; i<2; ++i){
		cin >> drink[i];
	}

	int ans = 4000;
	for(int i=0; i<3; ++i){
		for(int j=0; j<2; ++j){
			int set = burger[i] + drink[j] - 50;
			ans = min(ans, set);
		}
	}

	cout << ans;


	return 0;
}