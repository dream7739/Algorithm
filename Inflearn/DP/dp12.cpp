#include <iostream>
#include <vector>
using namespace std;

//12. 회장뽑기(플로이드-워샬 응용)
//점수가 가장 작은 사람이 회장

int main(){
    int n;  //회원수
    cin >> n;
    vector<vector<int> > dis(n+1, vector<int>(n+1, 100));
    vector<int> res(n+1, 0);
    
    for(int i = 0; ; i++){
        int a, b;
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        dis[a][b] = 1;
        dis[b][a] = 1;
    }
    
    for(int i = 0; i < n; i++){
        dis[i][i] = 0;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    
    int score = 100;  //회장 점수(최소값)
    int cnt = 0;      //회장 점수를 가진 사람 수
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            res[i] = max(res[i], dis[i][j]);
        }
        score = min(score, res[i]);
    }
    
    for(int i = 1; i <= n; i++){
        if(res[i] == score) cnt++;
    }
    
    cout << score << " " << cnt << "\n";
    
    for(int i= 1; i <= n; i++){
        if(res[i] == score) cout << i << " ";
    }
    
    return 0;
}
