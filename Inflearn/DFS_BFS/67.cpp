#include <iostream>
#include <vector>
using namespace std;

//67. 최소비용(DFS: 인접행렬)

int n, m, a, b, c;
int cost = 2147483647;
int chk[30];
int map[30][30];

void DFS(int v, int sum){
    if(v == n){
        cost = min(cost, sum);
    }else{
        for(int i = 1; i <= n; i++){
            if(map[v][i] > 0 && chk[i] == 0){
                chk[i] = 1;
                DFS(i, sum + map[v][i]);
                chk[i] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a >> b  >> c;
        map[a][b] = c;
    }
    chk[1] = true;
    DFS(1, 0);
    cout << cost << "\n";
    return 0;
}
