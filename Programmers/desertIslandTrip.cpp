#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> answer;
bool chk[101][101];
int row, col;
int sum;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int DFS(vector<string> maps, int x, int y){
    chk[x][y] = 1;
    sum += (maps[x][y]-'0');
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < row && ny >= 0 && ny < col){
            if(maps[nx][ny] != 'X' && chk[nx][ny] == false){
                DFS(maps, nx, ny);
            }
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    row = maps.size();
    col = maps[0].size();
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(maps[i][j] != 'X' && !chk[i][j]){
                sum = 0;
                answer.push_back(DFS(maps, i, j));
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    if(answer.empty()) answer.push_back(-1);
    return answer;
}
