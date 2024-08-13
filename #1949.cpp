/*
BackJoon No.
#1949
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int RANGE_MAX = 1e4;
const int RANDOM_ROOT = 1;

int nodeNum;
int weight[RANGE_MAX+1];
vector<int> edges[RANGE_MAX+1];
int dp[RANGE_MAX+1][3];
// ㄴ> 특정 노드를 루트로 하는 서브트리에 대해서~
//      0 : 루트가 우수마을일 때 -> 자식은 무조건 우수마을이 아님
//      1 : 루트가 평범마을이고, 조상이 우수마을  -> 자식이 모두 우수마을이 아니여도 됨, 완전 상관 무
//      2 : 루트가 평범마을이고, 조상이 평범마을  -> 자식 중 적어도 하나는 우수마을
bool isVisited[RANGE_MAX+1];

void dfs(int root){
    isVisited[root] = true;

    dp[root][0] = weight[root];
    dp[root][1] = 0;
    dp[root][2] = 0;

    bool tmp = false;
    int idx = -1;
    for(auto e : edges[root]){
        if(isVisited[e])    continue;

        dfs(e);

        // 0 : 루트가 우수마을일 때 -> 자식은 무조건 우수마을이 아님
        dp[root][0] += dp[e][1];

        // 1 : 루트가 평범마을이고, 조상이 우수마을  -> 자식이 모두 우수마을이 아니여도 됨, 완전 상관 무
        dp[root][1] += max(dp[e][0], dp[e][2]);

        // 2 : 루트가 평범마을이고, 조상이 평범마을  -> 자식 중 적어도 하나는 우수마을
        dp[root][2] += max(dp[e][0], dp[e][2]);
        if(dp[e][0] > dp[e][2]){
            tmp = true;
        }

        if(idx == -1 || dp[idx][0] < dp[e][0]){
            idx = e;
        }
    }

    if(!tmp && idx != -1){
        dp[root][2] -= dp[idx][2];
        dp[root][2] += dp[idx][0];
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> nodeNum;
    
    for(int i=1; i<=nodeNum; ++i)
        cin >> weight[i];

    for(int _=0; _<nodeNum-1; ++_){
        int node1, node2;
        cin >> node1 >> node2;
        edges[node1].push_back(node2);
        edges[node2].push_back(node1);
    }

    /*
    
    n = 1e4, 2초 -> O(n^2)
    주민수는 사실상 각 노드에 대한 가중치
    우수마을이라면~     자식은 우수마을이 아님
    우수마을이 아니라면~    자식 중 적어도 하나는 우수마을 -> 이거 처리를 어떻게 하지
        - 평범마을인데 부모가 우수마을인 경우엔 어떤 걸 고르더라도 상관없음
        - 평범마을인데 부모도 평범마을이라면 무조건 자식중에 하나는 우수마을이여야 함
        => 자식에서 부모로 올라가는 바텀업 방식인데 부모가 어떤 마을인지 어떻게 알지?????
            사실상 부모의 부모임
            걍 dp배열을 3갈래로 쪼갤까?

    즉 두 다리 건너서 띄어져있을 수도 있음 -> 평범마을은 연속으로 2개까지만 존재할 수 있음 -> 아님

    3%에서 틀렸습니다

    아니면 dp배열을 완성시키고 난 후 다시 훝으면서 찾아내는 건?

    경우를 아예 둘로 쪼개야 하나

    조상이 평범마을인 말단노드인 경우엔?

    */

   dfs(RANDOM_ROOT);

   cout << max(dp[RANDOM_ROOT][0], max(dp[RANDOM_ROOT][1], dp[RANDOM_ROOT][2]));

    return 0;
}