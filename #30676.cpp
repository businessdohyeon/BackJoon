/*
BackJoon No.
#30676
*/

#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int lamda;
	cin >> lamda;

	if(lamda > 780){
		// do nothin'
	}else if(lamda >= 620){
		cout << "Red";
	}else if(lamda >= 590){
		cout << "Orange";
	}else if(lamda >= 570){
		cout << "Yellow";
	}else if(lamda >= 495){
		cout << "Green";
	}else if(lamda >= 450){
		cout << "Blue";
	}else if(lamda >= 425){
		cout << "Indigo";
	}else if(lamda >= 380){
		cout << "Violet";
	}else{
		// do nothin'
	}

	return 0;
}