/*
BackJoon No.
#32642
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	long long anger = 0;
	long long ans = 0;
	for(int _=0; _<n; ++_){
		int isRaining;
		cin >> isRaining;

		if(isRaining){
			++anger;
		}else{
			--anger;
		}

		ans += anger;
	}

	cout << ans;

	return 0;
}