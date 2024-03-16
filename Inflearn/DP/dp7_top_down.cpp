#include <iostream>
using namespace std;

//7. 알리바바와 40인의 도둑(Top-Down)
int arr[21][21], dp[21][21];

int DFS(int x, int y){
    if(dp[x][y] > 0) return dp[x][y];
    if(x == 0 && y == 0) return arr[0][0];
    else if(x == 0) return dp[x][y] = arr[x][y] + DFS(0, y-1);
    else if(y == 0) return dp[x][y] = arr[x][y] + DFS(x-1, 0);
    else return dp[x][y] = arr[x][y] + min(DFS(x-1, y), DFS(x, y-1));
}

int main(){
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    cout << DFS(n-1, n-1);
    return 0;
}
