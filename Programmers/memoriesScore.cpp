#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> m;
    int score;
    
    for(int i = 0; i < name.size(); i++){
        m.insert({name[i], yearning[i]});
    }
    
    for(int i = 0; i < photo.size(); i++){
        score = 0;
        for(int j = 0; j < photo[i].size(); j++){
            if(m.count(photo[i][j]) > 0){
                score += m[photo[i][j]];
            }
        }
        answer.push_back(score);
    }
    
    return answer;
}
