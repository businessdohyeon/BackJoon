/*
BackJoon No.
#1271
*/

#include <iostream>
#include <string>

using namespace std;

bool comp(string a, string b){
	if(a.length() != b.length()){
		return (a.length() > b.length());
	}

	for(int i=0; i<a.length(); ++i){
		if(a[i] != b[i])	return (a[i] > b[i]);
	}
	return true;
}
void trim(string& str){
	int cnt = 0;
	while(str[cnt] == '0')
		++cnt;
	str = str.substr(cnt);

	if(str.length() == 0){
		str = "0";
	}
}
void A_subract_B(string& a, string& b){
	for(int idxA = a.length()-1, idxB = b.length()-1; idxB >=0; --idxA, --idxB){
		a[idxA] = (a[idxA] - b[idxB]) + '0';

		if(a[idxA] < '0'){
			--a[idxA-1];
			a[idxA] += 10;
		}
	}

	trim(a);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string a, b;
	cin >> a >> b;

	string quotient = "";
	string remainder = "";
	for(int i=0; i<a.length(); ++i){
		remainder += a[i];

		if(comp(remainder, b)){
			int cnt = 0;
			
			while(comp(remainder, b)){
				A_subract_B(remainder, b);
				++cnt;
			}

			quotient += ('0' + cnt);
		}else{
			quotient += '0';
		}
	}

	trim(quotient);
	trim(remainder);

	cout << quotient << '\n' << remainder;

	return 0;
}