#include <iostream>
using namespace std;

//58. 이진트리 깊이우선탐색(DFS)
void DFS(int v){
    if(v>7) return;
    else{
        //cout << v << ' ';   //전위순회
        DFS(v*2);            //왼쪽 자식노드
        //cout << v << ' ';   //중위 순회
        DFS(v*2+1);          //오른쪽 자식노드
        //cout << v. < ' ';   //후위 순회
    }
}
   
int main(){
    DFS(1);
    return 0;
}
