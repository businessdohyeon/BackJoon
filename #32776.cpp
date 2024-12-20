/*
BackJoon No.
#32776
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int sab, ma, fab, mb;
	cin >> sab >> ma >> fab >> mb;
	if(sab <= 240 || sab <= ma+fab+mb){
		cout << "high speed rail";
	}else{
		cout << "flight";
	}

	return 0;
}