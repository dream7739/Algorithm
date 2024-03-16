#include <iostream>
#include <vector>
using namespace std;

//5. 최대 선 연결하기
   
int main(){
    int n, res = 0;
    cin >> n;
    vector<int> arr(n+1), dp(n+1);
    
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++){
        int max = 0;
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j] && max < dp[j]){
                max = dp[j];
            }
        }
        dp[i] = max + 1;
        if(res < dp[i]) res = dp[i];
    }
    
    cout << res;
    return 0;
}
