#include <iostream>
using namespace std;

//59. 부분집합
int ch[11];
int n;

void DFS(int L){
    if(L == n+1){
        for(int i = 1; i <= n; i++){
            if(ch[i] == 1) cout << i << " ";
        }
        puts("");
    }else{
        ch[L] = 1;
        DFS(L+1);
        ch[L] = 0;
        DFS(L+1);
    }
}
   
int main(){
    cin >> n;
    DFS(1);
    return 0;
}
