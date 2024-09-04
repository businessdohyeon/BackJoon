/*
BackJoon No.
#2098
*/

#include <iostream>
#include <memory.h>

using namespace std;

const int RANGE_MAX = 16;
const int DP_INITIAL_VALUE = -1;
const int INF = 987654321;

int cityNum;
int cost[RANGE_MAX][RANGE_MAX];
int dp[RANGE_MAX][1 << RANGE_MAX];

int solve(int cur, int visitedBitMask){
	if(visitedBitMask == ~(0xFFFFFFFF << cityNum))	return cost[cur][0];

	int& curDp = dp[cur][visitedBitMask];
	if(curDp != DP_INITIAL_VALUE)					return curDp;

	curDp = INF;
	for(int next=0; next<cityNum; ++next){
		if(cost[cur][next] == 0)		continue;
		if(visitedBitMask & (1<<next))	continue;

		int result = solve(next, visitedBitMask | (1<<next));
		if(result == 0)					continue;

		int cal = result + cost[cur][next];
		curDp = min(curDp, cal);
	}

	return curDp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> cityNum;

	for(int from=0; from<cityNum; ++from)
		for(int to=0; to<cityNum; ++to)
			cin >> cost[from][to];

	memset(dp, DP_INITIAL_VALUE, sizeof(dp));

	cout << solve(0, 1);

	return 0;
}