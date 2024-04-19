#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int s = section.size();
    int cur = 0;
    
    for(int i = 0; i < s; i++){
        if(section[i] < cur) continue;
        cur = section[i] + m;
        answer++;
    }
    
    return answer;
}
