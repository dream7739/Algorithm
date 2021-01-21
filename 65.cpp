#include <stdio.h>
#include <algorithm>
using namespace std;
int map[10][10], ch[10][10], cnt=0;
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

//65. 미로 탐색(DFS)

void DFS(int n, int m){
    int i, xx, yy; //xx yy는 앞으로 갈 격자
    if(n==7 && m==7){
        cnt++;
    }else{
        for(i=0;i<4;i++){
            xx = n+dx[i];
            yy = m+dy[i];
            if(xx<1 || xx>7 || yy<1 || yy>7) continue;
            if(map[xx][yy]==0 && ch[xx][yy]==0){
                ch[xx][yy]=1;
                DFS(xx,yy);
                ch[xx][yy]=0;
            }
        }
    }
}

int main(){
    int i, j;
    for(i=1;i<=7;i++){
        for(j=1;j<=7;j++){
            scanf("%d", &map[i][j]);
        }
    }
    ch[1][1]=1; //1,1은 방문
    DFS(1,1);
    printf("%d\n", cnt);
}

