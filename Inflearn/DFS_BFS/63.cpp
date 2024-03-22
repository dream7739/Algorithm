#include <iostream>
using namespace std;

//63. 인접행렬(가중치 방향그래프)

int main(){
    int n, m, a, b, c;
    int arr[21][21];
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a >> b >> c;
        arr[a][b] = c;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
