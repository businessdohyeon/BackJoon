/*
BackJoon No.
#32775
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int s, f;
	cin >> s >> f;
	if(s > f){
		cout << "flight";
	}else{
		cout << "high speed rail";
	}

	return 0;
}