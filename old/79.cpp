#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int ch[30];

//79. 원더랜드(Prim MST 알고리즘)
//최소비용 트리

struct Edge{
    int e; //정점
    int val; //값
    Edge(int a, int b){
        e=a;
        val=b;
    }
    bool operator<(const Edge &b)const{
        return val>b.val; //최소힙
    }
};


int main(){
    priority_queue<Edge> Q;
    vector<pair<int, int> > map[30];
    int i, n, m, a, b, c, res=0;
    scanf("%d %d", &n, &m); //정점, 간선
    for(i=1;i<=m;i++){
        //무방향
        map[a].push_back(make_pair(b,c)); //a-b 연결
        map[b].push_back(make_pair(a,c)); //b-a 연결
    }
    Q.push(Edge(1,0));
    while(!Q.empty()){
        Edge tmp=Q.top();
        Q.pop(); //(1,0) Pop
        int v=tmp.e; //1
        int cost=tmp.val; //0
        
        //큐에서 나온 정점이 트리에 현재 속해있는 원소인지?(방문했는지)
        if(ch[v]==0){
            res+=cost;
            ch[v]=1;
            for(i=0;i<map[v].size();i++){
                Q.push(Edge(map[v][i].first, map[v][i].second));
            }
        }
    }
    printf("%d\n", res);
    return 0;
}


