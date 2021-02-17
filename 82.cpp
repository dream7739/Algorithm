#include <stdio.h>
#include <algorithm>
using namespace std;
int n, r, cnt=0;
int a[20], res[20], ch[20];

//82. 순열구하기 (DFS)
void DFS(int L){
    if(L==r){
        //마지막 레벨까지 가면 경로를 출력
        for(int j=0;j<L;j++){
            printf("%d ", res[j]);
        }
        cnt++;
        puts("");
    }else{
        for(int i=1;i<=n;i++){
            if(ch[i]==0){
                //방문한다
                res[L]=a[i];
                ch[i]=1;
                DFS(L+1);
                ch[i]=0;
            }
        }
    }
}


int main(){
    scanf("%d %d", &n, &r);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    DFS(0);
    printf("%d\n", cnt);
    return 0;
}
