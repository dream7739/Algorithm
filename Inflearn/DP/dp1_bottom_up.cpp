#include <iostream>
using namespace std;

//1. 네트워크 선 자르기(Bottom-Up)
int main(){
    int n;
    int dp[50];
 
    cin >> n;
    
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }
    
    cout << dp[n];
}
