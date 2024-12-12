/*
BackJoon No.
#31994
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string ans;
	int max = -1;
	for(int i=0; i<7; ++i){
		string str;
		int n;
		cin >> str >> n;

		if(n > max){
			max = n;
			ans = str;
		}
	}
	
	cout << ans;

	return 0;
}