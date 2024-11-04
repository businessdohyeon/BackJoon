/*
BackJoon No.
#4299
*/

#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int sum, diff;
	cin >> sum >> diff;

	if((sum + diff) % 2 != 0){
		cout << -1;
		return 0;
	}

	int a = (sum + diff) / 2;
	int b = sum - a;

	if(a >= 0 && b >= 0){
		if(a > b){
			cout << a << ' ' << b;
		}else{
			cout << b << ' ' << a;
		}
	}else{
		cout << -1;
	}

	return 0;
}