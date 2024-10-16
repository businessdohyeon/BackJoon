/*
BackJoon No.
#1874
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int size;
	cin >> size;

	stack<int> s;
	string str;
	bool isPossible = true;
	int tmp = 1;
	for(int _=0; _<size; ++_){
		int num;
		cin >> num;

		while((s.empty() || s.top() != num) && tmp <= size){
			s.push(tmp);
			str.push_back('+');
			++tmp;
		}

		if(s.empty() || s.top() != num){
			isPossible = false;
			break;
		}

		s.pop();
		str.push_back('-');
	}

	if(isPossible){
		for(const auto& ch : str){
			cout << ch << '\n';
		}
	}else{
		cout << "NO";
	}
	

	return 0;
}