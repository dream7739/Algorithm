#include <iostream>
using namespace std;

//65. 미로탐색(DFS)
int chk[8][8];
int arr[8][8];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt = 0;

void DFS(int x, int y){
    if(x == 7 && y == 7){
        cnt++;
    }else{
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx > 0 && nx <= 7 && ny > 0 && ny <= 7){
                if(arr[nx][ny] == 0 && chk[nx][ny] == 0){
                    chk[nx][ny] = 1;
                    DFS(nx, ny);
                    chk[nx][ny] = 0;
                }
            }
        }
    }
}

int main(){
    for(int i = 1; i <= 7; i++){
        for(int j = 1; j <= 7; j++){
            cin >> arr[i][j];
        }
    }
    chk[1][1] = 1;
    DFS(1, 1);
    cout << cnt << "\n";
    return 0;
}
