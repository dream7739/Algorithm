#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//81. 벨만-포드 알고리즘
//간선 개수에 따라 달라지는 거리값을 기록해 최소거리를 얻어낸다.
//음의 사이클이 존재하면 안됨

int dist[101];
struct Edge{
    int s;
    int e;
    int val;
    
    Edge(int a, int b, int c){
        s = a;
        e = b;
        val = c;
    }
};

int main(){
    vector<Edge> Ed;
    int n, m, i, j, a, b, c, s, e;
    cin >> n >> m;
    
    for(i = 1; i <= m; i++){
        cin >> a >> b >> c;
        Ed.push_back(Edge(a, b, c));
    }
    
    cin >> s >> e;
    
    for(i = 1; i <= n; i++){
        dist[i] = 2147000000;
    }
    
    dist[s] = 0;
    
    //n개 노드에서 n-1개의 간선이 발생한다.
    //n개 노드에서 n개의 간선이 발생할 경우 음의 사이클이 있는 것으로 간주
    for(i = 1; i < n; i++){
        for(j = 0; j < Ed.size(); j++){
            int u = Ed[j].s;
            int v = Ed[j].e;
            int w = Ed[j].val;
            
            if(dist[u] != 2147000000 && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    
    //n개의 간선이 발생할 경우
    for(i = 0; i < Ed.size(); i++){
        int u = Ed[j].s;
        int v = Ed[j].e;
        int w = Ed[j].val;
        
        if(dist[u] != 2147000000 && dist[u] + w < dist[v]){
            cout << -1 << endl;
            exit(0);
        }
    }
    
    cout << dist[e] << endl;
    return 0;
}
