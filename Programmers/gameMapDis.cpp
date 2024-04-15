#include<vector>
#include<queue>
using namespace std;

int n, m;
int answer = 0;
int chk[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(pair<int, int> p, vector<vector<int> > maps){
    queue<pair<int, int>> q;
    int fx, fy, nx, ny;
    chk[p.first][p.second] = 1;
    q.push(p);
    
    while(!q.empty()){
        pair<int, int> f = q.front();
        fx = f.first;
        fy = f.second;
        if(fx == n-1 && fy == m-1){
            return chk[fx][fy];
        }
        q.pop();
        for(int i = 0; i < 4; i++){
            nx = fx + dx[i];
            ny = fy + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(maps[nx][ny] == 0 || chk[nx][ny] > 0) continue;
            chk[nx][ny] = chk[fx][fy]+1;
            q.push({nx, ny});
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    n = maps.size();
    m = maps[0].size();
    answer = BFS({0, 0}, maps);
    return answer;
}
