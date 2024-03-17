#include <iostream>
#include <vector>
using namespace std;

//9. 동전교환(냅색 알고리즘)

int main(){
    int n, m;
    cin >> n;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cin >> m;
    vector<int> dp(m+1, 1000);
    dp[0] = 0;
    
    for(int i = 0; i < n; i++){
        int coin = arr[i];
        for(int j = arr[i]; j <= m; j++){
            dp[j] = min(dp[j-coin]+1, dp[j]);
        }
    }
    
    cout << dp[m];
    return 0;
}
