#include<stdio.h>
#include<vector>
using namespace std;
int n;
int map[30][30], cost=2147000000;
int ch[30];

//67. 최소비용(DFS: 인접행렬)
void DFS(int v, int sum){
    int i;
    if(v==n){
        if(sum<cost){
            cost=sum;
        }
    }else{
        for(i=1;i<=n;i++){
            if(map[v][i]>0 && ch[i]==0){
                ch[i]=1;
                DFS(i, sum+map[v][i]);
                ch[i]=0;
            }
        }
    }
}

int main(){
    int m, i, a, b, c;
    scanf("%d %d", &n, &m); //노드 간선
    for(i=1;i<=m;i++){
        scanf("%d %d %d", &a, &b, &c);
        map[a][b]=c;
    }
    ch[1]=1;
    DFS(1,0);
    printf("%d\n", cost);
}

