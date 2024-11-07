/*
BackJoon No.
#11280
*/

#include <iostream>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int varNum, caluseNum;
	cin >> varNum >> caluseNum;

	for(int i=0; i<caluseNum; ++i){
		int var1, var2;
		cin >> var1 >> var2;
	}

/*

절은 두 변수를 or한 것
절을 전부 ANDing해서 true가 가능한가

n = 1e5, m = 1e5

1sec, O(NM)	미만

전부 다 따지려고 들면 2^varNum

여기에 scc를 어떻게 끼얹으라는 거지?
애초에 그래프를 어떤 식으로?
절을 노드로? 아니면 변수를 노드로?

절을 노드로 한다고 치고 해당 절이 true일때 ture일 수 있는 노드로 간선을 보낸다고 하면?
절과 절 사이의 관계를 살핀다는 점 자체에서 실격
-> 아닌가 모든 노드에 대한 경우의 수가 아니라 절로만 따지니까 괜찮나

그럼 어떤식으로든 변수를 노드로 만들고 그래프로 만드는 느낌인데
변수를 true/ false를 나눠서 각 2개씩 노드를 만든다면?

안되는 경우를 생각하기가 어렵네
(1 || 2) && (1 || -2) && (-1 || -2) && (-1 || 2)

진짜 감 1도 안오네; 좀만 머리 굴려보고 바로 찾아봐야 할 듯

절로서 존재하지 않는 조합은? 그런 것들을 전부 고려하는 건 말이 안 됨

방향이 없는 그래프에서 scc를 논한다는 것도 말이 안 되는 거였네
그럼 방향을 잡아야 하는데....
어떻게????

간선을 불능으로 만들어야하나?

진짜 1도 모르겠네;;;;;

*/


	return 0;
}