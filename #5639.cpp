/*
BackJoon No.
#5639
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int RANGE_MAX = 10000;
vector<int> preOrder;
int parent[RANGE_MAX];
int leftChild[RANGE_MAX];
int rightChild[RANGE_MAX];

void postOrder(int parent){
    if(leftChild[parent] != -1)
        postOrder(leftChild[parent]);
    if(rightChild[parent] != -1)
        postOrder(rightChild[parent]);
    cout << preOrder[parent] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(preOrder.size() <= RANGE_MAX){
        int input;
        if(cin >> input)
            preOrder.push_back(input);
        else
            break;
    }

    int size = preOrder.size();

    fill(parent, parent+size, -1);
    fill(leftChild, leftChild+size, -1);
    fill(rightChild, rightChild+size, -1);

    for(int i=1; i<size; ++i){
        if(preOrder[i] < preOrder[i-1]){
            parent[i] = i-1;
            leftChild[i-1] = i;
        }else{
            int aptParent = 0;
            while(true){
                if(preOrder[i] < preOrder[aptParent])   aptParent = leftChild[aptParent];
                else
                    if(rightChild[aptParent] != -1)     aptParent = rightChild[aptParent];
                    else                                break;
            }

            parent[i] = aptParent;
            rightChild[aptParent] = i;
        }
    }

    postOrder(0);

    return 0;
}