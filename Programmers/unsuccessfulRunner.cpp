#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;
    
    for(const auto &p : participant){
        if(m.find(p) == m.end()) m[p] = 1;
        else if(m.find(p) != m.end()) m[p]++;
    }
    
    for(const auto &c : completion){
        if(m.find(c) != m.end()) m[c]--;
    }
    
    for(const auto &mp : m){
        if(mp.second == 1) {
            answer = mp.first;
            break;
        }
    }
    
    return answer;
}
