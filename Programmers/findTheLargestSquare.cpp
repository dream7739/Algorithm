#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//가장 큰 정사각형 찾기
int solution(vector<vector<int>> board)
{
    int answer = -1;
    int n = board.size();    //행
    int m = board[0].size(); //열
        
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(board[i][j] == 1){
                board[i][j] = min({board[i-1][j-1], board[i-1][j], board[i][j-1]}) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }
    return answer*answer;
}
