/*
BackJoon No.
#2530
*/

#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int hr, min, sec;
	cin >> hr >> min >> sec;

	int need;
	cin >> need;

	int total = hr*60*60 + min*60 + sec + need;
	cout << total/60/60%24 << ' ' << total/60%60 << ' ' << total%60;

	return 0;
}