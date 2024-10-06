/*
BackJoon No.
#1966
*/

#include <iostream>
#include <deque>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testNum;
	cin >> testNum;
	for(int _=0; _<testNum; ++_){
		int docNum, targetIdx;
		cin >> docNum >> targetIdx;

		int weight[docNum];
		for(int i=0; i<docNum; ++i){
			cin >> weight[i];
		}

		deque<int> dq;
		for(int i=0; i<docNum; ++i){
			dq.push_back(i);
		}

		int result = 0;
		while(true){
			int front = dq.front();
			dq.pop_front();

			bool flag = false;
			for(auto e : dq){
				if(weight[e] > weight[front]){
					flag = true;
					break;
				}
			}

			if(flag){
				dq.push_back(front);
			}else{
				++result;
				if(front == targetIdx){
					break;
				}
			}
		}

		cout << result << '\n';
	}

	return 0;
}