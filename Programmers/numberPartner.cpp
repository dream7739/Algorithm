#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> m1(10, 0);
    vector<int> m2(10, 0);
    
    int sizeX = X.size();
    int sizeY = Y.size();
    
    for(int i = 0; i < sizeX; i++){
        m1[X[i]-'0']++;
    }
    for(int i = 0; i < sizeY; i++){
        m2[Y[i]-'0']++;
    }
    
    for(int i = 9; i >= 0; i--){
        int cnt = min(m1[i], m2[i]);
        if(cnt > 0){
            for(int j = 0; j < cnt; j++){
                answer += to_string(i);
            }
        }
    }
    
    if(answer[0] == '0') answer = "0";
    else if(answer == "") answer = "-1";
    
    return answer;
}
