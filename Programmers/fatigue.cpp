#include <string>
#include <vector>

using namespace std;

int n;
int answer;
int chk[10];

void DFS(int cnt, int k, vector<vector<int>> dungeons){
    for(int i = 0; i < n; i++){
        if(chk[i] == 0 && dungeons[i][0] <= k){
            chk[i] = 1;
            DFS(cnt+1, k-dungeons[i][1], dungeons);
            chk[i] = 0;
        }
    }
    answer = max(answer, cnt);
}

int solution(int k, vector<vector<int>> dungeons) {
    n = dungeons.size();
    DFS(0, k, dungeons);
    return answer;
}
