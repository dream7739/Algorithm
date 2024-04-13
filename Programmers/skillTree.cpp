#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    string str;
    bool flag;
    
    for(int i = 0; i < skill_trees.size(); i++){
        queue q = queue<char>();
        str = skill_trees[i];
        flag = true;
        
        for(int j = 0; j < skill.size(); j++){
            q.push(skill[j]);
        }
        
        for(int k = 0; k < str.size(); k++){
            if(skill.find(str[k]) != std::string::npos){
                if(q.front() != str[k]){
                    flag = false;
                    break;
                }else{
                    q.pop();
                }
            }
        }
        if(flag) answer++;
    }
    
    return answer;
}
