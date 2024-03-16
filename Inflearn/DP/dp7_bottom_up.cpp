#include <iostream>
using namespace std;

//7. 알리바바와 40인의 도둑(Bottom-Up)
int main(){
    int n;
    int arr[21][21];
    int dp[21][21];
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    dp[0][0] = arr[0][0];
    
    for(int i = 0; i < n; i++){
        dp[i][0] = arr[i][0] + dp[i-1][0];
        dp[0][i] = arr[0][i] + dp[0][i-1];
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = arr[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    cout << dp[n-1][n-1];
    
    return 0;
}
