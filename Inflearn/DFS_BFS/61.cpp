#include <iostream>
using namespace std;

//61. 특정 수 만들기(DFS)

int n, m, cnt = 0;
int arr[11], path[11];

void DFS(int L, int sum){
    if(L == n+1){
        if(sum == m){
            cnt++;
            for(int i = 1; i < L; i++){
                cout << path[i] << " ";
            }
            cout << "\n";
        }
    }else{
        path[L] = arr[L];
        DFS(L+1, sum + arr[L]);
        path[L]  = -arr[L];
        DFS(L+1, sum - arr[L]);
        path[L] = 0;
        DFS(L+1, sum);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    DFS(1, 0);
    if(cnt == 0) cout << "-1";
    else cout << "YES";
    return 0;
}
