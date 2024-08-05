/*
BackJoon No.
#17472
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pos;
struct Edge{
    Pos island1, island2;
    int len;
};

const int RANGE_MAX = 10;
const int DELTA_ROW[] = {-1, 1, 0, 0};
const int DELTA_COL[] = {0, 0, -1, 1};

int n, m;
bool isIsland[RANGE_MAX][RANGE_MAX];
Pos unionFindArr[RANGE_MAX][RANGE_MAX];

Pos findRoot(const Pos& target){
    if(unionFindArr[target.first][target.second] == target)     return target;

    Pos root = findRoot(unionFindArr[target.first][target.second]);
    unionFindArr[target.first][target.second] = root;
    return root;
}
bool tryUnionFindMerge(const Pos& island1, const Pos& island2){
    Pos root_of_island1 = findRoot(island1);
    Pos root_of_island2 = findRoot(island2);

    if(root_of_island1 == root_of_island2)      return false;

    Pos child = max(root_of_island1, root_of_island2);
    Pos parent = min(root_of_island1, root_of_island2);

    unionFindArr[child.first][child.second] = parent;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    
    // 입력
    for(int row=0; row<n; ++row)
        for(int col=0; col<m; ++col)
            cin >> isIsland[row][col];

    // 유니온파인드 배열 초기화
    for(int row=0; row<n; ++row)
        for(int col=0; col<m; ++col)
            if(isIsland[row][col])
                unionFindArr[row][col] = {row, col};
            else
                unionFindArr[row][col] = {-1, -1};

    // 섬 먼저 연결
    for(int row=0; row<n; ++row){
        for(int col=0; col<m; ++col){
            if(!isIsland[row][col])     continue;

            for(int direction=0; direction<4; ++direction){
                int targetRow = row+DELTA_ROW[direction];
                int targetCol = col+DELTA_COL[direction];

                if(targetRow<0 || targetRow>=n || targetCol<0 || targetCol>=m)  continue;
                if(!isIsland[targetRow][targetCol])     continue;

                tryUnionFindMerge({row, col}, {targetRow, targetCol});
            }
        }
    }

    // 가능한 다리의 모든 경우의 수를 담은 백터 생성
    vector<Edge> bridgeGraph;
    for(int row=0; row<n; ++row){
        for(int col=0; col<m; ++col){
            if(!isIsland[row][col])     continue;

            for(int direction=0; direction<4; ++direction){
                int bridgeLen = 0;
                bool isOceanBetween = false;
                bool isActivated = false;
                Pos target = {row+DELTA_ROW[direction], col+DELTA_COL[direction]};
                while(target.first>=0 && target.first<n && target.second>=0 && target.second<m){
                    if(isIsland[target.first][target.second]){
                        if(isOceanBetween)     isActivated = true;
                        break;
                    }

                    isOceanBetween = true;
                    ++bridgeLen;

                    target.first += DELTA_ROW[direction];
                    target.second += DELTA_COL[direction];
                }

                if(!isActivated || bridgeLen <= 1)  continue;

                bridgeGraph.push_back({{row, col}, target, bridgeLen});
            }
        }
    }

    // greedy하게 하기 위해 길이 순으로 오름차순 정렬
    sort(bridgeGraph.begin(), bridgeGraph.end(), [](Edge a, Edge b){
        return a.len < b.len;
    });

    // 최소신장트리 만들면서 유니온 파인드 연결
    int minBridgeLen = 0;
    for(auto& bridge : bridgeGraph)
        if(tryUnionFindMerge(bridge.island1, bridge.island2))
            minBridgeLen += bridge.len;

    // 전부 다 연결되었는지 여부 확인
    bool isAllIslandConected = true;
    Pos commonroot = {-1, -1};
    for(int row=0; row<n; ++row){
        for(int col=0; col<m; ++col){
            if(!isIsland[row][col])     continue;

            Pos root = findRoot({row, col});
            if(commonroot == make_pair(-1, -1)){
                commonroot = root;
                continue;
            }

            if(root != commonroot){
                isAllIslandConected = false;
                break;
            }
        }
    }

    // 출력
    if(isAllIslandConected)     cout << minBridgeLen;
    else                        cout << -1;

    return 0;
}