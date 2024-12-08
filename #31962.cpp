/*
BackJoon No.
#31962
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, x;
	cin >> n >> x;

	int ans = -1;
	for(int i=0; i<n; ++i){
		int s, t;
		cin >> s >> t;

		if(s+t <= x){
			ans = max(ans, s);
		}
	}

	cout << ans;

	return 0;
}