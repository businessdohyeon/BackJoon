/*
BackJoon No.
#17626
*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int dp[n+1];
	fill(dp, dp+n+1, 0);

	for(int i=1; i<=n; ++i){
		dp[i] = dp[i-1]+1;

		for(int j=2; j<=sqrt(i); ++j){
			dp[i] = min(dp[i], dp[i - j*j] + 1);
		}
	}

	cout << dp[n];

	return 0;
}