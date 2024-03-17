#include <iostream>
#include <vector>
using namespace std;

//11. 플로이드 워샬 알고리즘

int main(){
    int n, m;
    cin >> n >> m; //도시 수, 도로 수
    vector<vector<int> > dis(n+1, vector<int>(n+1, 5000));
    
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = c;
    }
    
    for(int i = 1; i <= n; i++){
        dis[i][i] = 0;
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j =1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dis[i][j] == 5000) cout << "M" << " ";
            else cout << dis[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
