/*
BackJoon No.
#1786
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string textContent, searchString;
	getline(cin, textContent);
	getline(cin, searchString);

	const int textContentLen = textContent.length();
	const int searchStringLen = searchString.length();

	vector<int> fallback(searchStringLen, 0);
	for(int i=1, j=0; i<searchStringLen; ++i){
		while(j>0 && searchString[i] != searchString[j]){
			j = fallback[j-1];
		}

		if(searchString[i] == searchString[j]){
			++j;
			fallback[i] = j;
		}
	}

	vector<int> ans;
	for(int i=0, j=0; i<textContentLen; ++i){
		while(j>0 && textContent[i] != searchString[j]){
			j = fallback[j-1];
		}

		if(textContent[i] == searchString[j]){
			if(j == searchStringLen-1){
				ans.push_back(i - searchStringLen + 1);
				j = fallback[j];
			}else{
				++j;
			}
		}
	}
	
	cout << ans.size() << '\n';
	for(const int& idx : ans)
		cout << idx+1 << ' ';

	return 0;
}