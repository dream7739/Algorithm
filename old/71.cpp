#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int ch[10001], d[3]={1, -1, 5};

//71. 송아지 찾기 (BFS: 상태트리 탐색)
int main(){
    int s, e, i, x, pos;
    queue<int> Q;
    scanf("%d %d", &s, &e); //현재 위치 S, 송아지 위치 E
    ch[s]=1;
    Q.push(s);
    while(!Q.empty()){
        x=Q.front();
        Q.pop();
        for(i=0; i<3; i++){
            pos=x+d[i]; //가려고 하는 지점
            if(pos<=0 || pos>10000) continue;
            if(pos==e){
                printf("%d\n", ch[x]);
                exit(0);
            }if(ch[pos]==0){
                ch[pos]=ch[x]+1; //점프 횟수
                Q.push(pos);
            }
        }
    }
    return 0;
}


