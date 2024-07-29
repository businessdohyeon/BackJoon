/*
BackJoon No.
#1774
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Pos{
    int x, y;
};
struct Tunnel{
    int spaceship1, spaceship2;
    double length;
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

    int spaceshipNum, tunnelNum;
    cin >> spaceshipNum >> tunnelNum;

    Pos spaceship[spaceshipNum+1];
    for(int i=1; i<=spaceshipNum; ++i)
        cin >> spaceship[i].x >> spaceship[i].y;

    int unionFindArr[spaceshipNum+1];
    for(int i=1; i<=spaceshipNum; ++i)
        unionFindArr[i] = i;

    for(int _=0; _<tunnelNum; ++_){
        int a, b;
        cin >> a >> b;

        int root_of_a = findRoot(unionFindArr, a);
        int root_of_b = findRoot(unionFindArr, b);
        unionFindArr[max(root_of_a, root_of_b)] = min(root_of_a, root_of_b);
    }

    vector<Tunnel> tunnels;
    for(int i=1; i<=spaceshipNum-1; ++i){
        for(int j=i+1; j<=spaceshipNum; ++j){
            Pos& a = spaceship[i];
            Pos& b = spaceship[j];
            double distance = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
            
            tunnels.push_back({i, j, distance});
        }
    }

    sort(tunnels.begin(), tunnels.end(), [](Tunnel a, Tunnel b){
        if(a.length != b.length)            return a.length < b.length;
        if(a.spaceship1 != b.spaceship1)    return a.spaceship1 < b.spaceship1;
        return a.spaceship2 < b.spaceship2;
    });
    
    double ans = 0;
    for(auto t : tunnels){
        int root_of_starship1 = findRoot(unionFindArr, t.spaceship1);
        int root_of_starship2 = findRoot(unionFindArr, t.spaceship2);

        if(root_of_starship1 == root_of_starship2)      continue;

        unionFindArr[max(root_of_starship1, root_of_starship2)] = min(root_of_starship1, root_of_starship2);
        ans += t.length;
    }

    cout.precision(2);
    cout << fixed << ans;

    return 0;
}