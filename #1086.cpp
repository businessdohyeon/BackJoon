/*
BackJoon No.
#1086
*/

#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

typedef pair<long long, long long> Fraction;

const int RANGE_MAX = 16;
const int DP_INITIAL_VALUE = -1;
const int DIGIT_MAX = 50;
const int K_MAX = 100;

int setNum;
string set[RANGE_MAX];
int k;
int setModulo[RANGE_MAX];
int digitModulo[DIGIT_MAX+1];
long long dp[1 << RANGE_MAX][K_MAX+1];
/*
=> dp[K_MAX+1][1 << RANGE_MAX] 의 형태로 사용하는 것보다 캐시 적중률이 더 좋아서 실행시간 차이 발생
즉, 비트마스크를 1차원으로 설정하는 편이 2차원으로 설정하는 편보다 빠름
이는 재귀하는 cal함수 내부에서 인자로 넘겨지는 비트마스크(combinationBitMask)와 계산값(curNum)의 형태 차이에 있음
비트마스크는 낮은 비트부터 차오르는 식으로 주기적인 형태를 띄는 반면, 계산값은 이에 비하면 굉장히 무작위적임
메모리에 캐싱을 하게 되면 1차원의 관점에서 1만큼의 차이가 난다면 살제로는 2차원의 크기만큼 차이가 나게 됨
즉, 2차원의 차이가 적은 편보다 1차원의 차이가 적은 편이 캐시 적중률이 좋음
따라서 보다 주기적인 형태를 띄는 비트마스크를 1차원으로 사용하게 되면 캐싱 적중률이 올라감
이에 따라 백준 기준 300ms정도의 차이가 생김
*/

const int bigIntModulo(const string& str, const int divisor){
	int result = 0;
	for(auto ch : str)
		result = (result * 10 + (ch-'0')) % divisor;
	return result;
}
const long long cal(const long long& curNum, const int combinationBitMask) {
	if (combinationBitMask == (1 << setNum) - 1) 	return (curNum == 0);

	long long& curDp = dp[combinationBitMask][curNum];
	if (curDp != DP_INITIAL_VALUE)					return curDp;

	curDp = 0;
	for(int next=0; next<setNum; ++next){
		if (combinationBitMask & (1 << next)) continue;
        
		const long long nextNum = (curNum * digitModulo[set[next].size()] + setModulo[next]) % k;
		const int nextBitMask = combinationBitMask | (1 << next);
		curDp += cal(nextNum, nextBitMask);
	}
	return curDp;
}
const long long factorial(const int n){
	long long result = 1;
	for(int i=2; i<=n; ++i)
		result *= i;
	return result;
}
const long long gcd(const long long& a, const long long& b){
	if(b == 0)		return a;
	return gcd(b, a%b);
}

void getInput(){
	cin >> setNum;

	for(int i=0; i<setNum; ++i)
		cin >> set[i];

	cin >> k;
}
void init(){
	for(int i=0; i<setNum; ++i)
		setModulo[i] = bigIntModulo(set[i], k);

	digitModulo[0] = 1;
	for(int i=1; i<=DIGIT_MAX; ++i)
		digitModulo[i] = (digitModulo[i-1] * 10) % k;

	memset(dp, DP_INITIAL_VALUE, sizeof(dp));
}
void solve(){
	const long long numerator = cal(0, 0);
	const long long dominator = factorial(setNum);

	Fraction ans;
	if (numerator == 0) {
		ans = {0, 1};
	}else {
		const long long gcdResult = gcd(numerator, dominator);
		ans = {numerator / gcdResult, dominator / gcdResult};
	}

	cout << ans.first << '/' << ans.second;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	getInput();

	init();

	solve();
	
	return 0;
}