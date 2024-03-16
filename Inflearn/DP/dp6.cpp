#include <iostream>
#include <vector>
using namespace std;

//6. 가장 높은 탑 쌓기
struct Brick {
    int s, h, w;
    
    Brick(int a, int b, int c){
        s = a;
        h = b;
        w = c;
    }
    
    bool operator<(const Brick &b)const{
        return s > b.s;
    }
};


int main(){
    int n;
    vector<Brick> bricks;
    cin >> n;
    vector<int> dp(n);
    
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        bricks.push_back(Brick(a,b,c));
    }
    
    sort(bricks.begin(), bricks.end());
    dp[0] = bricks[0].h;
    int res = dp[0];
    
    for(int i = 1; i < n; i++){
        int max = 0;
        for(int j = 0; j < i; j++){
            if(bricks[i].w < bricks[j].w && max < dp[j]){
                max = dp[j];
            }
        }
        
        dp[i] = bricks[i].h + max;
        if(res < dp[i]) res = dp[i];
    }
    
    cout << res;
    return 0;
}
