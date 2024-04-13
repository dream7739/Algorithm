#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

string solution(string s) {
    unordered_map<char, int> um;
    string answer = "";
    
    for(const auto& str: s){
        um[str]++;
    }
    
    for(const auto& m : um){
        if(m.second == 1) answer += m.first;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
