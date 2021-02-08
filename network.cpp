#include <string>
#include <vector>
using namespace std;
int ch[201];

void DFS(vector<vector<int>>& v, int idx){
    
    for(int i = 0; i < v[idx].size(); i++){
        if(v[idx][i] == 1 && ch[i] == 0){
            //연결 && 방문하지 않은 노드
            ch[i] = 1;
            DFS(v, i);
        }
    }
}

int solution(int n, vector<vector<int>> v) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        if(ch[i]==0) {
            DFS(v, i);
            answer++;
        }
    }
    return answer;
}
