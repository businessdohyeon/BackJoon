/*
BackJoon No.
#2263
*/

#include <iostream>

using namespace std;

const int RANGE_MAX = 100000;

int n;
int inOrder[RANGE_MAX];
int idx_in_inOrder[RANGE_MAX+1];
int postOrder[RANGE_MAX];

void printPreOrder(int startIdx_in_inOrder, int endIdx_in_inOrder, int startIdx_in_postOrder, int endIdx_in_postOrder){
    if(startIdx_in_inOrder > endIdx_in_inOrder || startIdx_in_postOrder > endIdx_in_postOrder)
        return;

    int root = postOrder[endIdx_in_postOrder];
    int rootIdx_in_inOrder = idx_in_inOrder[root];

    cout << root << ' ';

    int offset = rootIdx_in_inOrder-startIdx_in_inOrder;
    printPreOrder(startIdx_in_inOrder, rootIdx_in_inOrder-1, startIdx_in_postOrder, startIdx_in_postOrder+offset-1);
    printPreOrder(rootIdx_in_inOrder+1, endIdx_in_inOrder, startIdx_in_postOrder+offset, endIdx_in_postOrder-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i=0; i<n; ++i){
        cin >> inOrder[i];
        idx_in_inOrder[inOrder[i]] = i;
    }

    for(int i=0; i<n; ++i)
        cin >> postOrder[i];

    printPreOrder(0, n-1, 0, n-1);

    return 0;
}