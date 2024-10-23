/*
BackJoon No.
#11726
*/

#include <iostream>

using namespace std;

const int M = 10007;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int dp[1001];
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3; i<=n; ++i){
		dp[i] = (dp[i-1] + dp[i-2]) % M;
	}

	cout << dp[n];

	return 0;
}