#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string str = "";
    
    for(int i = 0; i < my_string.size(); i++){
        char s = my_string[i];
        if(s != ' '){
            str += s;
        }else if( s == ' '){
            answer.push_back(str);
            str = "";
        }
    }
    
    answer.push_back(str);
    return answer;
}
