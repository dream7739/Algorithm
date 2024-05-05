#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//80. 다익스트라 알고리즘

struct Edge{
    int vex;
    int dis;
    
    Edge(int a, int b){
        vex = a;
        dis = b;
    }
    
    bool operator <(const Edge &b)const {
        return dis > b.dis; //작은 값이 위로 온다
    }
};

int main(){
    priority_queue<Edge> Q; //최소힙으로 최단거리 탐색
    
    vector<pair<int, int> > graph[30]; //연관관계
    
    int i, n, m, a, b, c;
    cin >> n >> m;
    
    vector<int> dist(n+1, 2147000000);
    
    for(int i = 1; i <= m; i++){
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    
    //1부터 탐색
    Q.push(Edge(1, 0));
    dist[1] = 0;
    
    while(!Q.empty()){
        int now = Q.top().vex;
        int cost = Q.top().dis;
        Q.pop();
        
        if(cost > dist[now]) continue;
        
        for(i = 0; i < graph[now].size(); i++){
            int next = graph[now][i].first;
            int nextDis = cost + graph[now][i].second;
            
            if(dist[next] > nextDis){
                dist[next] = nextDis;
                Q.push(Edge(next, nextDis));
            }
        }
    }
    
    for(i = 2; i <= n; i++){
        if(dist[i] != 2147000000) cout << i << " : " << dist[i] << endl;
        else cout << i << " : " << "impossible" << endl;
    }
}
