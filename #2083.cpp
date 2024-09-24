/*
BackJoon No.
#2083
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while(true){
		string name;
		int age, weight;
		
		cin >> name >> age >> weight;

		if(name == "#" && age == 0 && weight == 0)		break;

		cout << name << ' ' << ((age > 17 || weight >= 80) ? "Senior" : "Junior") << '\n';
	}

	return 0;
}