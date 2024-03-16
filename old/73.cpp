#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

//73. 최대힙 (우선순위 큐)
int main(){
    int a;
    priority_queue<int> pQ;
    
    while(true){
        scanf("%d", &a);
        if(a==-1) break;
        if(a==0){
            if(pQ.empty()) printf("-1\n");
            else{
                printf("%d\n", pQ.top());
                pQ.pop(); //팝하면 루트 노드가 pop
            }
        }
        else pQ.push(a); //push하면 부모랑 비교해서 큰 게 위쪽 레벨로 올라감
    }
    return 0;
}


