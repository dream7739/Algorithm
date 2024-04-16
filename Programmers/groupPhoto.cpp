#include <string>
#include <vector>

using namespace std;
int answer;
string s;
int ch[10];

void DFS(int L, string str, vector<string> data){
    if(L == 8){
        bool flag = true;
        for(int i = 0; i < data.size(); i++){
            string condition = data[i];
            char m1 = condition[0]; //대상자 1
            char m2 = condition[2]; //대상자 2
            char op = condition[3]; //연산자
            int bet = condition[4] - '0'; //둘 사이에 있어야 할 사람 수
            
            int num = str.find(m1) - str.find(m2); //실제 둘 사이 사람 수
            if(num < 0) num = (-1) * num;
            num -= 1;
            
            if(op == '=' && bet == num){
                continue;
            }else if(op == '<' && bet > num){
                continue;
            }else if(op == '>' && bet < num){
                continue;
            }else{
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }else{
        for(int i = 0; i < 8; i++){
            if(ch[i] == 0){
                ch[i] = 1;
                DFS(L+1, str + s[i], data);
                ch[i] = 0;
            }
        }
    }
}


int solution(int n, vector<string> data) {
    answer = 0;
    s = "ACFJMNRT";
    fill(ch, ch + 10, 0);
    DFS(0, "", data);
    return answer;
}
