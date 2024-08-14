/*
BackJoon No.
#2166
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<long double, long double> Pos;

long double calTriangleArea(const Pos& a, const Pos& b, const Pos& c){
    return ((a.first*b.second + b.first*c.second + c.first*a.second) - (a.second*b.first + b.second*c.first + c.second*a.first)) / 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int vertexNum;
    cin >> vertexNum;

    Pos vertex[vertexNum];
    for(int i=0; i<vertexNum; ++i)
        cin >> vertex[i].first >> vertex[i].second;

    long double area = 0;
    for(int i=1; i<=vertexNum-2; ++i)
        area += calTriangleArea(vertex[0], vertex[i], vertex[i+1]);

    cout.precision(1);
    cout << fixed << abs(area);

    return 0;
}