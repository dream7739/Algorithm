#include <iostream>
#include <vector>
using namespace std;

//8. 가방문제(냅색 알고리즘)

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> dp(m+1);
    
    for(int i = 0; i < n; i++){
        int w, v; //무게, 가치
        cin >> w >> v;
        for(int j = w; j <= m; j++){
            dp[j] = max(dp[j-w] + v, dp[j]);
        }
    }
    
    cout << dp[m];
    return 0;
}
