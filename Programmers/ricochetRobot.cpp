#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int chk[100][100];
int startX, startY;
int row, col;

int BFS(vector<string>& board){
    queue<pair<int, int> > q;
    q.push({startX, startY});
    chk[startX][startY] = 1;
    
    while(!q.empty()){
        pair<int, int> top = q.front();
        int x = top.first;
        int y = top.second;
        
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x;
            int ny = y;
            
            while(1){
                if(nx + dx[i] < 0 || nx + dx[i] >= row || ny + dy[i] < 0 || ny + dy[i] >= col) break;
                if(board[nx + dx[i]][ny + dy[i]] == 'D') break;
                nx += dx[i];
                ny += dy[i];
            }
            
            if(chk[nx][ny] == 0){
                chk[nx][ny] = chk[x][y] + 1;
                q.push({nx, ny});
                
                if(board[nx][ny] == 'G') return chk[nx][ny];
            }
            
        }
    }
    return 0;
}

int solution(vector<string> board) {
    row = board.size();
    col = board[0].length();
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(board[i][j] == 'R'){
                startX = i;
                startY = j;
            }
        }
    }
    
    return BFS(board) - 1;
}
