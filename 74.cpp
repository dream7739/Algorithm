#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

//74. 최소힙 (우선순위 큐)
//부모노드의 값이 왼쪽 자식과 오른쪽 자식보다 작아야함 => 가장작은 값이 루트에 들어감
// -5는 -6보다 큼 => 최대힙 구조로 -5가 루트, -6이 자식이 됨 => 최소힙 구현 시 -를 +로 바꿔서 출력
int main(){
    int a;
    priority_queue<int> pQ;

    while(true){
        scanf("%d", &a);
        if(a==-1) break;
        if(a==0) {
            if(pQ.empty()) printf("-1\n");
            else{
                printf("%d\n", -pQ.top());
                pQ.pop();
            }
        }
        else pQ.push(-a);
    }

    return 0;
}


