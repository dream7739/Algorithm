#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    int n = board.size();
    
    for(int i = 0; i < moves.size(); i++){
        int idx = moves[i] - 1;
        int num = 0;
        
        for(int j = 0; j < n; j++){
            if(board[j][idx] != 0){
                num = board[j][idx];
                board[j][idx] = 0;
                break;
            }
        }
        
        if(num == 0) continue;
        
        if(s.empty()){
            s.push(num);
        }else if(!s.empty()){
            if(s.top() == num){
                s.pop();
                answer += 2;
            }else{
                s.push(num);
            }
        }
    }
    
    return answer;
}
