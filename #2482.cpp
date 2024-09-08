/*
BackJoon No.
#2482
*/

#include <iostream>

using namespace std;

constexpr int RANGE_MAX = 1000;
constexpr int DIVISOR = 1000000003;

int n, k;
int dp[RANGE_MAX][RANGE_MAX+1][2];

void initDp(){
	for(int total=0; total<=k; ++total){
		for(int isChosen=0; isChosen<2; ++isChosen){
			dp[0][total][isChosen] = 0;
		}
	}
}
void calDp(){
	for(int i=1; i<n; ++i){
		dp[i][0][0] = dp[i-1][0][0];
		dp[i][0][1] = 0;

		for(int total=1; total<=k; ++total){
			dp[i][total][0] = (dp[i-1][total][0] + dp[i-1][total][1]) % DIVISOR;
			dp[i][total][1] = dp[i-1][total-1][0];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;

	int ans = 0;

	initDp();
	dp[0][0][0] = 1;
	calDp();
	ans = (ans + dp[n-1][k][0] + dp[n-1][k][1]) % DIVISOR;

	initDp();
	dp[0][1][1] = 1;
	calDp();
	ans = (ans + dp[n-1][k][0]) % DIVISOR;

	cout << ans;

	return 0;
}