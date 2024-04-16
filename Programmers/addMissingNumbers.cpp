#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int ch[10] = {0, };
    
    for(const auto& n : numbers){
        ch[n] = 1;
    }
    
    for(int i = 0; i < 10; i++){
        if(ch[i] == 0) answer += i;
    }
    return answer;
}
