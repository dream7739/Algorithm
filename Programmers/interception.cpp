#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//[1 4][4 5][3 7][4 8][5 12][11 13][10 14]
bool cmp(vector<int> &v1, vector<int> &v2){
    if(v1[1] == v2[1]){
        return v1[0] < v2[0];
    }else{
        return v1[1] < v2[1];
    }
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int num = -1;
    sort(targets.begin(), targets.end(), cmp);
    for(int i = 0; i < targets.size(); i++){
        int s = targets[i][0];
        int e = targets[i][1];
        
        if(num <= s){
            num = e;
            answer++;
        }
    }
    
    return answer;
}
