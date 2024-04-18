#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for(int i = 0; i < quiz.size(); i++){
        string str = quiz[i];
        int idx1, idx2;
        int num1, num2, num3;
        char op;
        bool flag = false;
        
        if(str.find(' ') != string::npos){
            idx1 = str.find(' ') + 1;
            op = str[idx1];
        }
        
        if(str.find('=') != string::npos){
            idx2 = str.find('=');
        }
        
        num1 = stoi(str.substr(0, idx1 - 1));
        num2 = stoi(str.substr(idx1 + 1, idx2 - 1));
        num3 = stoi(str.substr(idx2 + 1));
        
        if(op == '+'){
            if(num1 + num2 == num3) flag = true;
        } else if(op == '-'){
            if(num1 - num2 == num3) flag = true;
        }
        
        if(flag) answer.push_back("O");
        else answer.push_back("X");
    }
    
    return answer;
}
