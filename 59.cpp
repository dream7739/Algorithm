#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, ch[11];

//59. 부분집합(DFS 완전탐색
void DFS(int L){
    if(L==n+1){
     //종료지점
        int i;
        for(i=1;i<=n;i++){
            if(ch[i]==1) printf("%d",i);
        }
        puts(""); //줄바꿈
    }
    else{
        ch[L]=1;
        DFS(L+1);
        ch[L]=0;
        DFS(L+1);
    }
}

int main(){
    scanf("%d", &n);
    DFS(1); //1Level
    return 0;
}
