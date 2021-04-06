#include <stdio.h>
#include <algorithm>
int arr[101], n;

int DFS(int L){
    if(arr[L]>0) return arr[L];
    if(L==1 || L==2){
        return L;
    }else{
        return arr[L]=DFS(L-2)+DFS(L-1);
    }
}

int main(){
    scanf("%d", &n);
    printf("%d\n", DFS(n));
    return 0;
}