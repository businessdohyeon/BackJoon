/*
BackJoon No.
#5596
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int info, math, sci, eng;

	cin >> info >> math >> sci >> eng;
	int totalA = info + math + sci + eng;

	cin >> info >> math >> sci >> eng;
	int totalB = info + math + sci + eng;

	cout << max(totalA, totalB);

	return 0;
}