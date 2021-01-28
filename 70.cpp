#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int ch[30], dis[30];

//70. 그래프 최단거리(BFS)
int main(){
    //1번 정점에서 각 정점으로 가는 최소 간선수 2번 정점부터(방향그래프)
    int n, m, i, a, b, x; //n: 정점 수, m: 간선 수
    vector<int> map[30];
    queue<int> Q;
    scanf("%d %d", &n, &m);
    for(i= 1; i<=m; i++){
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
    }
    Q.push(1);
    ch[1]=1;
    while(!Q.empty()){
        x=Q.front();
        Q.pop();
        for(i=0;i<map[x].size();i++){
            if(ch[map[x][i]]==0){
                ch[map[x][i]]=1;
                Q.push(map[x][i]);
                dis[map[x][i]]=dis[x]+1;
            }
        }
    }
    for(i=2;i<=n;i++){
        printf("%d : %d\n", i, dis[i]);
    }
    return 0;
}


