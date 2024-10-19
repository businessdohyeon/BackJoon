/*
BackJoon No.
#15829
*/

#include <iostream>

using namespace std;

const long long M = 1234567891;
const long long R = 31;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int len;
	cin >> len;

	char str[len+1];
	for(int i=0; i<len; ++i){
		cin >> str[i];
	}

	long long powArr[len+1];
	powArr[0] = 1;
	for(int i=1; i<=len; ++i){
		powArr[i] = powArr[i-1] * R % M;
	}

	long long ans = 0;
	for(int i=0; i<len; ++i){
		ans += (str[i] - 'a' + 1) * powArr[i];
		ans %= M;
	}

	cout << ans;

	return 0;
}