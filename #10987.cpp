/*
BackJoon No.
#10987
*/

#include <iostream>
#include <string>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string str;
	cin >> str;

	int cnt = 0;
	for(char ch : str){
		if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
			++cnt;
		}
	}
	
	cout << cnt;

	return 0;
}