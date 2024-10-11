/*
BackJoon No.
#27294
*/

#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, s;
	cin >> t >> s;

	if(s == 0 && 12 <= t && t <= 16){
		cout << 320;
	}else{
		cout << 280;
	}

	return 0;
}