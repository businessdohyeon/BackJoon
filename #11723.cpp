/*
BackJoon No.
#11723
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m;
	cin >> m;

	unsigned int s = 0x00000000;
	for(int _=0; _<m; ++_){
		string command;
		cin >> command;

		int x;
		if(command == "add"){
			cin >> x;
			s = s | (1 << x);
		}else if(command == "remove"){
			cin >> x;			
			s = s & ~(1 << x);
		}else if(command == "check"){
			cin >> x;
			cout << int((s & (1 << x)) != 0) << '\n';
		}else if(command == "toggle"){
			cin >> x;
			s = s ^ (1 << x);
		}else if(command == "all"){
			// 0000 0000 0001 1111 1111 1111 1111 1110
			s = 0x001FFFFE;
		}else if(command == "empty"){
			s = 0x00000000;
		}else{
			// do nothin'
		}
	}

	return 0;
}