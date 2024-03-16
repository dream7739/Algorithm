#include <stdio.h>
#include <algorithm>
using namespace std;
int map[30][30], ch[30], cnt=0, n;
//64. 경로 탐색(DFS)

void DFS(int v){
    int i;
    if(v==n){
        //종료지점?
        cnt++;
    }else{
        //갈 수 있는 정점 찾기
        for(i=1;i<=n;i++){
            if(map[v][i]==1 && ch[i]==0){
                ch[i]=1;
                DFS(i);
                ch[i]=0;
            }
        }
    }
}

int main(){
    int i, m, a, b;
    scanf("%d %d", &n, &m);
    for(i=1;i<=m;i++){
        scanf("%d %d", &a, &b);
        map[a][b]=1;
    }
    ch[1]=1;
    DFS(1);
    printf("%d\n", cnt);
}

