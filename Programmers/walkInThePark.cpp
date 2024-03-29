#include <string>
#include <map>
#include <vector>
using namespace std;

int startX, startY, nx, ny;
int n, m;
bool flag;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
map<string, int> board = {{"N", 0}, {"S", 1}, {"E", 2}, {"W", 3}};

void findRoute(vector<string> park, vector<string> routes){
    int nx, ny;
    
    for(int i = 0; i < routes.size(); i++){
        string route = routes[i];
        string dir = route.substr(0, 1);
        int cnt = stoi(route.substr(2, 1));
        
        flag = true;
        nx = startX;
        ny = startY;
        
        for(int i = 0; i < cnt; i++){
            nx += dx[board[dir]];
            ny += dy[board[dir]];
            if(park[nx][ny] == 'X' || nx  < 0 || nx >= n || ny < 0 || ny >= m){
                flag = false;
                break;
            }
        }
        
        if(flag){
            startX = nx;
            startY = ny;
        }
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    n = park.size();
    m = park[0].size();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(park[i][j] == 'S'){
                startX = i;
                startY = j;
            }
        }
    }
    
    findRoute(park, routes);
    answer.push_back(startX);
    answer.push_back(startY);
    
    return answer;
}
