#include <iostream>
using namespace std;

//64. 경로 탐색(DFS)

int cnt = 0;
int n, m;
int arr[21][21];
int chk[21];

void DFS(int v){
    if(v == n){
        cnt++;
    }else{
        for(int i = 1; i <= n; i++){
            if(arr[v][i] == 1 && chk[i] == false){
                chk[i] = 1;
                DFS(i);
                chk[i] = 0;
            }
        }
    }
}

int main(){
    int a, b;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        arr[a][b] = 1;
    }
    chk[1] = true;
    DFS(1);
    cout << cnt << "\n";
    return 0;
}
