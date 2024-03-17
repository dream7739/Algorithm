#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//13. 위상정렬(그래프 정렬)
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > dis(n+1, vector<int>(n+1, 0));
    vector<int> degree(n+1, 0);
    queue<int> q;
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        dis[a][b] = 1;
        degree[b]++;
    }
    
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        int f = q.front();
        cout << f << " ";
        q.pop();
        
        for(int i = 1; i <= n; i++){
            if(dis[f][i] == 1){
                degree[i]--;
                if(degree[i] == 0) q.push(i);
            }
        }
    }
    
    return 0;
}
