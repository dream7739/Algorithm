#include <string>
#include <vector>

using namespace std;

int student[30];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int i = 0; i < lost.size(); i++){
        student[lost[i]] -= 1;
    }
    
    for(int i = 0; i < reserve.size(); i++){
        student[reserve[i]] += 1;
    }
    
    for(int i = 1; i <= n; i++){
        if(student[i] == -1){
            if(student[i-1] == 1){
                student[i-1] = student[i] = 0;
            }else if(student[i+1] == 1){
                student[i+1] = student[i] = 0;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(student[i] != -1) answer++;
    }
    return answer;
}
