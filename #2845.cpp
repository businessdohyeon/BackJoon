/*
BackJoon No.
#2845
*/

#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int personPerArea, area;
	cin >> personPerArea >> area;

	int guessNum[5];
	for(int i=0; i<5; ++i){
		cin >> guessNum[i];
	}

	int correctNum = personPerArea * area;
	for(int i=0; i<5; ++i){
		cout << guessNum[i] - correctNum << ' ';
	}

	return 0;
}