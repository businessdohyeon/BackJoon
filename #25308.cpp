/*
BackJoon No.
#25308
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<double, double> Pos;

const double SQRT_OF_2 = sqrt(2);

int stat[8];
int ans = 0;

Pos getPos(int statValue, int seqNum){
    switch (seqNum){
    case 0:
        return {0, statValue};
    case 1:
        return {SQRT_OF_2*statValue, SQRT_OF_2*statValue};
    case 2:
        return {statValue, 0};
    case 3:
        return {SQRT_OF_2*statValue, -SQRT_OF_2*statValue};
    case 4:
        return {0, -statValue};
    case 5:
        return {-SQRT_OF_2*statValue, -SQRT_OF_2*statValue};
    case 6:
        return {-statValue, 0};
    case 7:
        return {-SQRT_OF_2*statValue, SQRT_OF_2*statValue};
    default:
        return {0, 0};
    }
}
bool isConcave(int statValueA, int seqNumA, int statValueB, int seqNumB, int statValueC, int seqNumC){
    Pos posA = getPos(statValueA, seqNumA);
    Pos posB = getPos(statValueB, seqNumB);
    Pos posC = getPos(statValueC, seqNumC);
    return (posA.first*posB.second + posB.first*posC.second + posC.first*posA.second)-(posA.second*posB.first + posB.second*posC.first + posC.second*posA.first);
}

void solve(vector<int> seq, bool isChosen[], int target){
    int size = seq.size();
    if(isConcave(stat[seq[size-3]], size-3, stat[seq[size-2]], size-2, stat[seq[size-1]], size-1)){
        return;
    }
    
    /*
    
    0 1 2
    1 2 3
    2 3 4
    3
    4
    5 6 7

    6 7 0
    7 0 1
    
    */
    
    if(seq.size() == 8){
        if(isConcave(stat[seq[6]], 6, stat[seq[7]], 7, stat[seq[0]], 0)){
            return;
        }
        if(isConcave(stat[seq[7]], 7, stat[seq[0]], 0, stat[seq[1]], 1)){
            return;
        }

        ++ans;
        return;
    }


    isChosen[target] = true;

    for(int i=0; i<8; ++i){
        if(isChosen[i])     continue;

        seq.push_back(i);
        solve(seq, isChosen, i);
        seq.pop_back();
    }

    isChosen[target] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
    2초, 1024mb = 2^10
    8! = 40320
    걍 모든 경우의 수를 따지면 안되나
    재귀 돌려서 백트래킹?
    45도인것보니까 좌표를 임의로 줘서 세점 가지고 ccw돌려서 오목여부 판단하는 것 같은데
    순서 상관있으니까 순열임

    */
    
    for(int i=0; i<8; ++i)
        cin >> stat[i];

    for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            if(i == j)      continue;

            vector<int> seq;
            seq.push_back(i);
            seq.push_back(j);

            bool isChosen[8];
            fill(isChosen, isChosen+8, false);

            solve(seq, isChosen, j);
        }
    }


    cout << ans;


    return 0;
}