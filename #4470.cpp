/*
BackJoon No.
#4470
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N; string input;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; ++i)
	{
		getline(cin, input);
		cin.clear();
		cout << i + 1 << ". " << input << endl;
	}

	return 0;
}
