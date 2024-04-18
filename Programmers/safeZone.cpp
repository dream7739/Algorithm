#include <string>
#include <vector>

using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int chk[100][100];

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 1){
                chk[i][j] = 1;
                for(int k = 0; k < 8; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n || chk[nx][ny] == 1) continue;
                    chk[nx][ny] = 1;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(chk[i][j] == 0) answer++;
        }
    }
    
    return answer;
}
