/*
BackJoon No.
#24883
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	char ch;
	cin >> ch;
	if(ch == 'N' || ch == 'n'){
		cout << "Naver D2";
	}else{
		cout << "Naver Whale";
	}

	return 0;
}