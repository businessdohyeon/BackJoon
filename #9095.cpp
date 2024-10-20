/*
BackJoon No.
#9095
*/

#include <iostream>

using namespace std;

int cnt(int n){
	if(n<0)		return 0;
	if(n==0)	return 1;

	return cnt(n-1)+cnt(n-2)+cnt(n-3);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testNum;
	cin >> testNum;

	for(int i=0; i<testNum; ++i){
		int n;
		cin >> n;

		cout << cnt(n) << '\n';
	}

	return 0;
}