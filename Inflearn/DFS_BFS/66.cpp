#include <iostream>
#include <vector>
using namespace std;

//66. 경로 탐색(DFS)

int n, m, a, b;
int cnt = 0;
int chk[30];
vector<int> map[30];

void DFS(int v){
    if(v == n){
        cnt++;
    }else{
        for(int i = 0; i < map[v].size(); i++){
            if(chk[map[v][i]] == 0){
                chk[map[v][i]] = 1;
                DFS(map[v][i]);
                chk[map[v][i]] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        map[a].push_back(b);
    }
    
    chk[1] = true;
    DFS(1);
    cout << cnt;
    return 0;
}
