#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int n = wallpaper.size();
    int m = wallpaper[0].size();
    int lux, luy, rdx, rdy;
    lux = luy = 51;
    rdx = rdy =  -1;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char s = wallpaper[i][j];
            if(s == '.') continue;
            lux = min(lux, i);
            luy = min(luy, j);
            rdx = max(rdx, i);
            rdy = max(rdy, j);
        }
    }
    answer = {lux, luy, rdx+1, rdy+1};
    return answer;
}
