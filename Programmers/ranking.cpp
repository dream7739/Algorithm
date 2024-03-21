#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
    
    for(int i = 0; i < n; i++){
        int x = results[i][0];
        int y = results[i][1];
        dp[x][y] = 1;
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dp[i][k] == 1 && dp[k][j] == 1){
                    dp[i][j] = 1;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(dp[i][j] || dp[j][i]) cnt++;
        }
        if(cnt == n-1) answer++;
    }
    
    return answer;
}
