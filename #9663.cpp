/*
BaekJoon No
#9663
*/
// 6시간 동안 끙끙대다가 백기 들었더니 문제 이해를 잘못한 거였더라;;

#include <iostream>
#include <vector>

using namespace std;


void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void nQueen(vector< pair<int,int> >* p_queenCase, int size, int* p_cnt, int beforeRow){
    if(p_queenCase->size() == size){
        ++(*p_cnt);
        return;
    }
    
    int row = beforeRow+1;

    for(int i=0; i<size; ++i){
        bool isCellAvaliable = true;
        for(auto queenPos : *p_queenCase){
            if(i == queenPos.second || row - queenPos.first == i - queenPos.second || row - queenPos.first == queenPos.second - i){
                isCellAvaliable = false;
                break;
            }
        }
        if(!isCellAvaliable)    continue;

        p_queenCase->push_back(make_pair(row, i));

        nQueen(p_queenCase, size, p_cnt, row);

        p_queenCase->pop_back();
    }
}

int main(){
    setDefault();

    int n;
    cin >> n;

    vector< pair<int,int> > queenCase;
    int cnt = 0;
    nQueen(&queenCase, n, &cnt, -1);

    cout << cnt;

    return 0;
}