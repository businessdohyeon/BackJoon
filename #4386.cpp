/*
BackJoon No.
#4386
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

struct Pos{
    double x, y;
};
struct Edge{
    int star1Idx, star2Idx;
    double weight;
};

bool compare(Edge a, Edge b){
    if(a.weight != b.weight)        return a.weight < b.weight;
    if(a.star1Idx != b.star1Idx)    return a.star1Idx < b.star1Idx;
    return a.star2Idx < b.star2Idx;
}
int findRoot(int unionFindArr[], int target){
    if(unionFindArr[target] == target)      return target;

    int root = findRoot(unionFindArr, unionFindArr[target]);
    unionFindArr[target] = root;
    return root;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int starNum;
    cin >> starNum;

    Pos star[starNum];
    for(int i=0; i<starNum; ++i)
        cin >> star[i].x >> star[i].y;

    vector<Edge> edges;
    for(int i=0; i<starNum-1; ++i){
        for(int j=i+1; j<starNum; ++j){
            Pos& s1 = star[i];
            Pos& s2 = star[j];
            double distance = sqrt(pow((s1.x-s2.x), 2) + pow((s1.y-s2.y), 2));

            edges.push_back({i, j, distance});
        }
    }

    sort(edges.begin(), edges.end(), compare);

    int unionFindArr[starNum];
    for(int i=0; i<starNum; ++i)
        unionFindArr[i] = i;

    double ans = 0;
    for(auto& e : edges){
        int root_of_star1 = findRoot(unionFindArr, e.star1Idx);
        int root_of_star2 = findRoot(unionFindArr, e.star2Idx);

        if(root_of_star1 == root_of_star2)  continue;

        unionFindArr[max(root_of_star1, root_of_star2)] = min(root_of_star1, root_of_star2);
        ans += e.weight;
    }

    cout.precision(2);
    cout << ans;

    return 0;
}