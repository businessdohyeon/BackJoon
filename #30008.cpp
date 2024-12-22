/*
BackJoon No.
#30008
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	for(int i=0; i<k; ++i){
		int g;
		cin >> g;

		int p = g * 100 / n;

		int ans;
		if(p <= 4){
			ans = 1;
		}else if(p <= 11){
			ans = 2;
		}else if(p <= 23){
			ans = 3;
		}else if(p <= 40){
			ans = 4;
		}else if(p <= 60){
			ans = 5;
		}else if(p <= 77){
			ans = 6;
		}else if(p <= 89){
			ans = 7;
		}else if(p <= 96){
			ans = 8;
		}else if(p <= 100){
			ans = 9;
		}else{
			// do nothin'
		}
		cout << ans << ' ';
	}

	return 0;
}