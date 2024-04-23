#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m;
    int scores[7] = {3, 2, 1, 0, 1, 2, 3};
    
    for(int i = 0; i < survey.size(); i++){
        string str = survey[i];
        int select = choices[i];
        int score = 0;
        char a = str[0];
        char b = str[1];
        
        score = scores[select-1];
        
        if(select == 4) continue;
        else if(select < 4){
            m[a] += score;
        }else if(select > 4){
            m[b] += score;
        }
    }
    
    vector<pair<char, char> > tmp = {{'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}};
    
    for(int i = 0; i < tmp.size(); i++){
        pair<int, int> p = tmp[i];
        char a = p.first;
        char b = p.second;
        if(m[a] >= m[b]) answer += a;
        else answer += b;
    }
    
    return answer;
}
