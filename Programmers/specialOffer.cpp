#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> m;
    
    for(int i = 0; i < want.size(); i++){
        m[want[i]] = number[i];
    }
    
    for(int i = 0; i < discount.size() - 9; i++){
        unordered_map<string, int> s;
        for(int j = i; j < i + 10; j++){
            s[discount[j]]++;
        }
        
        if(m == s) answer++;
    }
    
    return answer;
}
