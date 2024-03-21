#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int answer = (25*50) + 1;   //최대 피로도 * 최대 광물개수 + 1로 최댓값설정
unordered_map<string, int> m = {{"diamond", 0}, {"iron", 1}, {"stone", 2}};
int fatigue[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};

void DFS(vector<int> &picks, vector<string> &minerals, int sum, int location){
    if(location == minerals.size() || picks[0] + picks[1] + picks[2] == 0){
        answer = min(answer, sum);
    }
    
    for(int i = 0; i < 3; i++){
        if(picks[i] != 0){
            picks[i]--;
            int tmpSum = sum;
            int tmpIdx = location;
            for(;tmpIdx < location+5; tmpIdx++){
                if(tmpIdx == minerals.size()) break;
                tmpSum += fatigue[i][m[minerals[tmpIdx]]];
            }
            DFS(picks, minerals, tmpSum, tmpIdx);
            picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    DFS(picks, minerals, 0, 0);
    return answer;
}
