/*
BackJoon No.
#1003
*/

#include <iostream>

using namespace std;

const int RANGE_MAX = 40;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testNum;
	cin >> testNum;

	int zeroCntArr[RANGE_MAX+1];
	int oneCntArr[RANGE_MAX+1];

	zeroCntArr[0] = 1;
	oneCntArr[0] = 0;
	zeroCntArr[1] = 0;
	oneCntArr[1] = 1;

	for(int i=2; i<=RANGE_MAX; ++i){
		zeroCntArr[i] = zeroCntArr[i-1] + zeroCntArr[i-2];
		oneCntArr[i] = oneCntArr[i-1] + oneCntArr[i-2];
	}

	for(int i=0; i<testNum; ++i){
		int n;
		cin >> n;

		cout << zeroCntArr[n] << ' ' << oneCntArr[n] << '\n';
	}

	return 0;
}