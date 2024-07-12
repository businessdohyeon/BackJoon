/*
BackJoon No.
#1991
*/

#include <iostream>
#include <map>

using namespace std;

int n;
map<char, pair<char, char> > tree;

void preOrder(char start){
    cout << start;
    if(tree[start].first != '.')
        preOrder(tree[start].first);
    if(tree[start].second != '.')
        preOrder(tree[start].second);
}
void inOrder(char start){
    if(tree[start].first != '.')
        inOrder(tree[start].first);
    cout << start;
    if(tree[start].second != '.')
        inOrder(tree[start].second);
}
void postOrder(char start){
    if(tree[start].first != '.')
        postOrder(tree[start].first);
    if(tree[start].second != '.')
        postOrder(tree[start].second);
    cout << start;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int _=0; _<n; ++_){
        char target, left, right;
        cin >> target >> left >> right;
        tree[target] = make_pair(left, right);
    }

    preOrder('A');
    cout << '\n';

    inOrder('A');
    cout << '\n';

    postOrder('A');

    return 0;
}