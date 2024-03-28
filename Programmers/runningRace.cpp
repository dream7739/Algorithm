#include <string>
#include <map>
#include <vector>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer = players;
    map<string, int> m;
    
    for(int i = 0; i < players.size(); i++){
        m.insert({players[i], i});
    }
    
    for(int i = 0; i < callings.size(); i++){
        int loc = m[callings[i]];
        m[answer[loc-1]] += 1;
        m[callings[i]] -= 1;
        
        string tmp = answer[loc];
        answer[loc] = answer[loc-1];
        answer[loc-1] = tmp;
    }
    
    return answer;
}
