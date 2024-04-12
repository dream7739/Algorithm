#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int maxCnt = 0;
    int cnt, idx;
    unordered_map<int, int> tmp;
    
    for(int i = 0; i < array.size(); i++){
        tmp[array[i]]++;
    }
    
    for(const auto& tp : tmp){
        cnt = tp.second;
        idx = tp.first;
        
        if(cnt > maxCnt){
            maxCnt = cnt;
            answer = idx;
        }else if(cnt == maxCnt){
            answer = -1;
        }
    }
    
    return answer;
}
