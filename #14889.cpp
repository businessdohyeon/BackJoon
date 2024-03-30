/*
BaekJoon No
#14889
*/

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void setDefault(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void findMinGap(int n, int** powerMatrix, int* p_minGap, vector<int>* p_team1){
    int team1Size = p_team1->size();

    if(team1Size == n/2){
        vector<int> team2;
        for(int i=0; i<n; ++i){
            bool isInTeam1 = false;
            for(int member : *p_team1){
                if(i == member){
                    isInTeam1 = true;
                    break;
                }
            }

            if(isInTeam1)
                continue;
            else
                team2.push_back(i);
        }

        int team1_sum = 0;
        for(int i=0; i<n/2-1; ++i){
            for(int j=i+1; j<n/2; ++j){
                int member1 = p_team1->at(i);
                int member2 = p_team1->at(j);

                team1_sum += powerMatrix[member1][member2];
                team1_sum += powerMatrix[member2][member1];
            }
        }

        int team2_sum = 0;
        for(int i=0; i<n/2-1; ++i){
            for(int j=i+1; j<n/2; ++j){
                int member1 = team2[i];
                int member2 = team2[j];

                team2_sum += powerMatrix[member1][member2];
                team2_sum += powerMatrix[member2][member1];
            }
        }
        
        int gap = team1_sum - team2_sum;
        if(gap<0) gap *= -1;

        if(*p_minGap == -1 || gap < *p_minGap)
            *p_minGap = gap;

        return;
    }
    
    int start = team1Size != 0 ? p_team1->back()+1 : 0;

    for(int i=start; i<n; ++i){
        p_team1->push_back(i);
        findMinGap(n, powerMatrix, p_minGap, p_team1);
        p_team1->pop_back();
    }
}

int main(){
    setDefault();

    int n;
    cin >> n;

    int** powerMatrix = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; ++i)
        powerMatrix[i] = (int*)malloc(n*sizeof(int));

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> powerMatrix[i][j];

    int minGap = -1;
    vector<int> team1;
    findMinGap(n, powerMatrix, &minGap, &team1);

    cout << minGap;
    
    for(int i=0; i<n; ++i)
        free(powerMatrix[i]);
    free(powerMatrix);

    return 0;
}