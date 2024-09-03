/*
BackJoon No.
#1311
*/

#include <iostream>
#include <memory.h>

using namespace std;

const int RANGE_MAX = 20;

int n;
int cost[RANGE_MAX][RANGE_MAX];
int dp[RANGE_MAX][1 << 20];

int getDp(int target, int combinationMask){
	if(target == n)		return 0;

	int& targetDp = dp[target][combinationMask];
	if(targetDp != -1)	return targetDp;

	for(int i=0; i<n; ++i){
		if(combinationMask & (1 << i))	continue;

		int dfsResult = getDp(target+1, combinationMask | (1 << i)) + cost[target][i];
		if(targetDp == -1 || targetDp > dfsResult)
			targetDp = dfsResult;
	}

	return targetDp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			cin >> cost[i][j];

	memset(dp, -1, sizeof(dp));

	cout <<	getDp(0, 0);

	return 0;
}