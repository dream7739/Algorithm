#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//70. 그래프 최단거리(BFS)

int n, m, a, b;

vector<int> map[30];
int dis[30], ch[30];

int main(){
    queue<int> q;
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        map[a].push_back(b);
    }
    
    ch[1] = 1;
    q.push(1);
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int i = 0; i < map[front].size(); i++){
            if(ch[map[front][i]] == 0){
                ch[map[front][i]] = 1;
                dis[map[front][i]] = dis[front] + 1;
                q.push(map[front][i]);
            }
        }
    }
    
    for(int i = 2; i <= n; i++){
        cout << i << " : " << dis[i] << "\n";
    }
    
    return 0;
}
