/*
BackJoon No.
#17388
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int a, b, c;
	cin >> a >> b >> c;

	if(a+b+c >= 100){
		cout << "OK";
	}else{
		int tmp = min(a, min(b, c));
		if(tmp == a){
			cout << "Soongsil";
		}else if(tmp == b){
			cout << "Korea";
		}else if(tmp == c){
			cout << "Hanyang";
		}else{
			// do nothin'
		}
	}

	return 0;
}