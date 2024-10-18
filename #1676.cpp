/*
BackJoon No.
#1676
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int tenCnt = 0, twoCnt = 0, fiveCnt = 0;
	for(int i=1; i<=n; ++i){
		int tmp = i;

		while(tmp % 10 == 0){
			++tenCnt;
			tmp /= 10;
		}

		while(tmp % 5 == 0){
			++fiveCnt;
			tmp /= 5;
		}

		while(tmp % 2 == 0){
			++twoCnt;
			tmp /= 2;
		}
	}

	int ans = tenCnt + min(fiveCnt, twoCnt);
	cout << ans;

	return 0;
}