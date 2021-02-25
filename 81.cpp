#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
int dist[101];
using namespace std;

//81. 벨만-포드 알고리즘
//간선을 한 번만에 갈 수 있다, 두 번만에 갈 수 있다 등등
//정점 5개면 간선은 4번만에 가는게 가장 긴 경로

struct Edge{
    int s;
    int e;
    int val;
    Edge(int a, int b, int c){
        s=a;
        e=b;
        val=c;
    }
};

int main(){
    int i, j, n, m, a, b, c, s, e;
    vector<Edge> Ed;
    scanf("%d %d", &n, &m); //노드, 간선
    for(i=0;i<m;i++){
        scanf("%d %d %d", &a, &b, &c);
        Ed.push_back(Edge(a,b,c));
    }
    for(i=1;i<=n;i++){
        dist[i]=2147000000;
    }
    scanf("%d %d", &s, &e);
    dist[s]=0; //출발점 0 초기화
    for(i=1;i<n;i++){
        for(j=0;j<Ed.size();j++){
            int u= Ed[j].s;
            int v= Ed[j].e;
            int w=Ed[j].val;
            if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }
    //음의 사이클이 있는지 확인 (n번쨰!)
    for(j=0;j<Ed.size();j++){
        int u=Ed[j].s;
        int v=Ed[j].e;
        int w=Ed[j].val;
        if(dist[u]!=2147000000 & dist[u]+w<dist[v]){
            printf("-1\n");
            exit(0);
        }
    }
    printf("%d\n", dist[e]);
    return 0;
}
