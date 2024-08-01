/*
BackJoon No.
#6497
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Path{
    int house1, house2, weight;
};

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

    while(true){
        int houseNum, pathNum;
        cin >> houseNum >> pathNum;

        if(houseNum == 0 && pathNum == 0)   break;;

        int totalWeight = 0;
        vector<Path> paths;
        for(int _=0; _<pathNum; ++_){
            int house1, house2, weight;
            cin >> house1 >> house2 >> weight;
            paths.push_back({house1, house2, weight});
            totalWeight += weight;
        }

        sort(paths.begin(), paths.end(), [](Path a, Path b){
            if(a.weight != b.weight)    return a.weight < b.weight;
            if(a.house2 != b.house2)    return a.house2 < b.house2;
            return a.house1 < b.house1;
        });

        int unionFindArr[houseNum];
        for(int i=0; i<houseNum; ++i)
            unionFindArr[i] = i;

        int costSum = 0;
        for(auto p : paths){
            int root_of_house1 = findRoot(unionFindArr, p.house1);
            int root_of_house2 = findRoot(unionFindArr, p.house2);

            if(root_of_house1 == root_of_house2)    continue;

            unionFindArr[max(root_of_house1, root_of_house2)] = min(root_of_house1, root_of_house2);
            costSum += p.weight;
        }

        cout << totalWeight - costSum << '\n';
    }

    return 0;
}