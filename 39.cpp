#include <stdio.h>
#include <algorithm>
using namespace std;
int a[101], b[101], c[101];

//39. 두 배열 합치기
int main(){
    int i, n, m, p1=1, p2=1, p3=1;
    scanf("%d",&n); //a배열 개수
    for(i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    scanf("%d",&m); //b배열 개수
    for(i=1;i<=m;i++){
        scanf("%d", &b[i]);
    }
    
    while(p1<=n && p2<=m){
        if(a[p1]<b[p2]){
            c[p3++]=a[p1++];
        }else{
            c[p3++]=b[p2++];
        }
    }
    
    //남은 쪽 채우기
    while(p1<=n) c[p3++]=a[p1++];
    while(p2<=m) c[p3++]=b[p2++];
    
    for(i=1;i<p3;i++){
        printf("%d ", c[i]);
    }
    
    
    return 0;
}

