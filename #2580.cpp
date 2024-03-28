/*
BaekJoon No
#2580
*/

#include <iostream>
#include <vector>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool checkNum(int board[9][9], int row, int col, int value){
    for(int i=0; i<9; ++i)
        if(board[row][i] == value)
            return false;

    for(int i=0; i<9; ++i)
        if(board[i][col] == value)
            return false;

    int firstRowForSquare = row/3 * 3;
    int firstColForSquare = col/3 * 3;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            int targetRow = firstRowForSquare+i;
            int targetCol = firstColForSquare+j;
            if(board[targetRow][targetCol] == value)
                return false;
        }
    }

    return true;
}

void fillSudoku(int board[9][9], vector< pair<int,int> > emptyCells, int num, bool* p_isOnceSucessed){
    if(*p_isOnceSucessed)    return;

    if(num == emptyCells.size()){
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j)
                cout << board[i][j] << ' ';
            cout << '\n';
        }
        *p_isOnceSucessed = true;
        return;
    }

    for(int i=1; i<=9; ++i){
        int row = emptyCells[num].first;
        int col = emptyCells[num].second;

        if(checkNum(board, row, col, i)){
            board[row][col] = i;

            fillSudoku(board, emptyCells, num+1, p_isOnceSucessed);

            board[row][col] = 0;
        }
    }
}

int main(){
    setDefault();

    int board[9][9];
    vector< pair<int,int> > emptyCells;
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            cin >> board[i][j];
            if(board[i][j] == 0)
                emptyCells.push_back(make_pair(i, j));
        }
    }

    bool isOnceSucessed = false;
    fillSudoku(board, emptyCells, 0, &isOnceSucessed);

    return 0;
}