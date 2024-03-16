#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int n, map[10][10], dis[10][10];
int dx[4]={0, 1, 0, -1};
int dy[4]={-1, 0, 1, 0};

//88. 미로의 최단거리 통로(BFS)

struct Loc{
    int x;
    int y;
    Loc(int a, int b){
        x=a;
        y=b;
    }
};

queue<Loc> Q;

int main(){
    for(int i=1;i<=7;i++){
        for(int j=1;j<=7;j++){
            scanf("%d", &map[i][j]);
        }
    }
    Q.push(Loc(1,1));
    map[1][1]=1;
    while(!Q.empty()){
        Loc tmp=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int xx=tmp.x+dx[i];
            int yy=tmp.y+dy[i];
            if(map[xx][yy]==0 && xx>=1 && xx<=7 && yy>=1 && yy<=7){
                Q.push(Loc(xx, yy));
                map[xx][yy]=1;
                dis[xx][yy]=dis[tmp.x][tmp.y]+1;
            }
        }
    }
    printf("%d", dis[7][7]);
    return 0;
}

