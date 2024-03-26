#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//71. 송아지 찾기(BFS)

int ch[10001];
int dx[3] = {-1, 1, 5};

int main(){
    int s, e, x, pos;
    queue<int> q;
    
    cin >> s >> e;
    
    q.push(s);
    ch[s] = 1;
    
    while(!q.empty()){
        x = q.front();
        q.pop();
        
        for(int i = 0; i < 3; i++){
            pos = x + dx[i];
            if(pos < 1 && pos > 10000) continue;
            if(pos == e){
                cout << ch[x] << "\n";
                exit(0);
            }
            if(ch[pos] == 0){
                ch[pos] = ch[x] + 1;
                q.push(pos);
            }
        }
    }
    
    return 0;
}

