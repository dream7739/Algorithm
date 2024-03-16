#include <iostream>
using namespace std;

//3. 돌다리 건너기(Bottom-Up)
   
int main(){
    int n, dp[50];
    cin >> n;
    
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i <= n+1; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }
    
    cout << dp[n+1];
    return 0;
}
