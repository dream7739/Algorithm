#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, answer = 0;
pair<int, int> s;
pair<int, int> e;
pair<int, int> l;

int BFS(pair<int,int> st, pair<int, int> dst, vector<string> maps){
    int chk[100][100];
    fill(chk[0], chk[100], 0);
    queue<pair<int, int>> q;
    
    q.push(st);
    
    while(!q.empty()){
        pair<int, int> f = q.front();
        int fx = f.first;
        int fy = f.second;
        q.pop();
        
        if(fx == dst.first && fy == dst.second) return chk[fx][fy];
        
        for(int i = 0; i < 4; i++){
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            
            if(nx >= 0 && ny >= 0 &&
               nx < n && ny < m &&
               chk[nx][ny] == 0 && maps[nx][ny] != 'X'){
                q.push({nx, ny});
                chk[nx][ny] = chk[fx][fy] + 1;
            }
            
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    n = maps.size();
    m = maps[0].size();
    
    int cnt = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maps[i][j] == 'S'){
                s = {i, j};
                cnt++;
            }else if(maps[i][j] == 'E'){
                e = {i, j};
                cnt++;
            }else if(maps[i][j] == 'L'){
                l = {i, j};
                cnt++;
            }
            if(cnt == 3) break;
        }
    }
    
    int p1 = BFS(s, l, maps);
    int p2 = BFS(l, e, maps);
    
    if(p1 == -1 || p2 == -1) answer = -1;
    else answer = p1 + p2;
    
    return answer;
}
