#include <iostream>
#include <vector>
using namespace std;

//4. 최대 부분 증가수열
   
int main(){
    int n, res=0;
    cin >> n;
    vector<int> arr(n+1);
    vector<int> dp(n+1, 1);
    
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    for(int i = 2; i <= n; i++){
        int max = 0;
        for(int j = 1; j < i; j++){
            if(arr[j] < arr[i] && dp[j] > max){
                max = dp[j];
            }
        }
        dp[i] += max;
        if(res < dp[i]) res = dp[i];
    }
    
    cout << res;
            
    return 0;
}
