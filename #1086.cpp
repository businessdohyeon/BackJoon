/*
BackJoon No.
#1086
*/

#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

typedef pair<int, int> Fraction;

const int RANGE_MAX = 16;
const int DP_INITIAL_VALUE = -1;

int setNum;
int s[RANGE_MAX];
int k;
int dp[RANGE_MAX][1 << RANGE_MAX];

int solve(int cur, int combinationBitMask, int depth){
	if(combinationBitMask == ~(0xFFFFFFFF << setNum)){
		if(cur % k == 0){
			return 1;
		}
		return 0;
	}
	
	int& curDp = dp[cur][combinationBitMask];
	if(curDp != DP_INITIAL_VALUE)	return curDp;

	curDp = 0;
	for(int i=0; i<setNum; ++i){
		if(combinationBitMask & (1<<i))		continue;

		curDp += solve(i, combinationBitMask | (1<<i), depth+1);
	}


	return curDp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> setNum;
	
	for(int i=0; i<setNum; ++i)
		cin >> s[i];

	cin >> k;

	memset(dp, DP_INITIAL_VALUE, sizeof(dp));

	int numerator = 0;
	for(int i=0; i<setNum; ++i)
		numerator += solve(i, (1<<i));

	int dominator = 1;
	for(int i=1; i<=setNum; ++i)
		dominator *= i;

	Fraction ans;
	if(numerator == 0){
		ans = {0, 1};
	}else if(numerator == dominator){
		ans = {1, 1};
	}else{

	}

	cout << ans.first << '/' << ans.second;

/*

	n = 15
	2초, 128mb
	k는 두자리수 정수
	각수의 길이 최대는 50
	합친 수의 최대 길이는 50*15 = 750

	나누어 떨어지는 경우의 수 / 전체 경우의 수

	나누어 떨어짐의 판단을 어떻게? bigInt인데? 

	15bit < 2byte

	dp[지금선택하려고하는것]][조합]

	첫시작을 각각 다르게 해서 n번만큼 돌려야 하나?

*/


	return 0;
}