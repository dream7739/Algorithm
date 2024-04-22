#include <string>
#include <vector>
#include <map>

using namespace std;
vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> m;
    
    for(int i = 0; i < keymap.size(); i++){
        for(int j = 0; j < keymap[i].size(); j++){
            char s = keymap[i][j];
            int idx = j+1;
            if(m.find(s) != m.end()){
                if(m[s] > idx){
                    m[s] = idx;
                }
            }else{
                m.insert({keymap[i][j], idx});
            }
        }
    }
    
    for(int i = 0; i < targets.size(); i++){
        int cnt = 0;
        for(int j = 0; j < targets[i].size(); j++){
            char s = targets[i][j];
            if(m.find(s) != m.end()){
                cnt += m[s];
            }else{
                cnt = -1;
                break;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}
