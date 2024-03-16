#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, a[11], answer=0, path[11];

//61. 특정 수 만들기
void DFS(int L, int sum){
    if(L==n+1){
        //완성된 경우
        if(sum==m){
            answer++;
            for(int i=1;i<L;i++){
                printf("%d ", path[i]);
            }
            puts(""); //줄바꿈
        }
    }else{
        path[L]=a[L];
        DFS(L+1, sum+a[L]);
        path[L]=-a[L];
        DFS(L+1, sum-a[L]);
        path[L]=0;
        DFS(L+1, sum);
    }
}

int main(){
    int i;
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    DFS(1, 0);
    if(answer==0) printf("-1\n");
    else printf("%d\n", answer);
    return 0;
}

