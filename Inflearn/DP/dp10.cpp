#include <iostream>
#include <vector>
using namespace std;

//10. 최대점수 구하기(냅색 알고리즘)
//중복으로 문제를 풀 수 없다는 조건이 있음

int main(){
    int n, m;
    cin >> n >> m; //문제 개수, 제한시간
    vector<int> dp(m+1, 0);
    
    for(int i = 0; i < n; i++){
        int s, t;
        cin >> s >> t;
        for(int j = m; j >= t; j--){
            dp[j] = max(dp[j-t]+s, dp[j]);
        }
    }
    
    cout << dp[m];
    return 0;
}
