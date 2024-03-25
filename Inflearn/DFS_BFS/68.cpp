#include <iostream>
#include <vector>
using namespace std;

//68. 최소비용(DFS: 가중치 방향그래프 인접리스트)

int n, m, a, b, c;
int cost = 2147483647;
int chk[30];
vector<pair<int, int> > map[30];

void DFS(int v, int sum){
    if(v == n){
        cost = min(cost, sum);
    }else{
        for(int i = 0; i < map[v].size(); i++){
            if(chk[map[v][i].first] == 0){
                chk[map[v][i].first] = 1;
                DFS(map[v][i].first, sum+map[v][i].second);
                chk[map[v][i].first] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a >> b  >> c;
        map[a].push_back(make_pair(b, c));
    }
    chk[1] = true;
    DFS(1, 0);
    cout << cost << "\n";
    return 0;
}
