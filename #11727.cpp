/*
BackJoon No.
#11727
*/

#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int dp[n+1];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	for(int i=3; i<=n; ++i){
		dp[i] = dp[i-1] + 2*dp[i-2];
		dp[i] %= 10007;
	}

	cout << dp[n];

	return 0;
}