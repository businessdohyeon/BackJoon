/*
BackJoon No.
#1305
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int len;
	cin >> len;

	char str[len+1];
	cin >> str;

	vector<int> fallback(len, 0);
	for(int i=1, j=0; i<len; ++i){
		while(j>0 && str[i] != str[j]){
			j = fallback[j-1];
		}

		if(str[i] == str[j]){
			++j;
			fallback[i] = j;
		}
	}

	cout << len - fallback[len-1];

	return 0;
}