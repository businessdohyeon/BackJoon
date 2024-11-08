/*
BackJoon No.
#11280
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// node범위는 3 ~ (2*varNum+1)
constexpr int VAR_NUM_MAX = 1e5;
constexpr int RANGE_MAX = 2*VAR_NUM_MAX + 1;

int varNum, caluseNum;
vector<int> graph[RANGE_MAX+1];
int visitId;
int visitIdArr[RANGE_MAX+1];
int sccId;
int sccIdArr[RANGE_MAX+1];
vector<int> tarjanStack;

int convert(int n){
	return n > 0 ? 2*n : -2*n + 1;
}

int tarjan(int root){
	++visitId;
	visitIdArr[root] = visitId;

	tarjanStack.push_back(root);

	int minVisitId = visitId;
	for(const auto& e : graph[root]){
		if(visitIdArr[e] == 0){
			minVisitId = min(minVisitId, tarjan(e));
		}else if(sccIdArr[e] == 0){
			minVisitId = min(minVisitId, visitIdArr[e]);
		}else{
			// do nothin'
		}
	}

	if(minVisitId == visitIdArr[root]){
		++sccId;

		while(!tarjanStack.empty()){
			int back = tarjanStack.back();
			tarjanStack.pop_back();

			sccIdArr[back] = sccId;

			if(back == root)	break;
		}
	}

	return minVisitId;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> varNum >> caluseNum;

	for(int _=0; _<caluseNum; ++_){
		int var1, var2;
		cin >> var1 >> var2;
		
		graph[convert(-var1)].push_back(convert(var2));
		graph[convert(-var2)].push_back(convert(var1));
	}

	for(int node=3; node<=RANGE_MAX; ++node){
		if(visitIdArr[node] == 0){
			tarjan(node);
		}
	}

	for(int var=1; var<=varNum; ++var){
		if(sccIdArr[convert(var)] == sccIdArr[convert(-var)]){
			cout << 0;
			return 0;
		}
	}

	cout << 1;

	return 0;
}