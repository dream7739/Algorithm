#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

//58. 이진트리 깊이 우선 탐색(DFS)
void D(int v){
    if(v>7) return;
    else{
        printf("%d ", v); //전위순회
        D(v*2); //왼쪽 자식 노드
//        printf("%d ", v); //중위순회
        D(v*2+1); //오른쪽 자식 노드
        printf("%d ", v); //후위순회

    }
}

int main(){
    D(1);
    return 0;
}
