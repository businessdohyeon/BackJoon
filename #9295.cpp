/*
BackJoon No.
#9295
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int testNum;
	cin >> testNum;

	for(int i=1; i<=testNum; ++i){
		int a, b;
		cin >> a >> b;
		cout << "Case " << i << ": " << a+b << '\n';
	}

	return 0;
}