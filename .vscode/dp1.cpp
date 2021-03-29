#include <stdio.h>
#include <algorithm>
using namespace std;
int dy[50];
//DP1. 네트워크 선 자르기(Bottom-Up)
//작은 문제 > 큰 문제로 확대
int main(){
    int n;
    scanf("%d", &n);
    dy[1]=1; 
    dy[2]=2;
    for(int i=3;i<=n;i++){
        dy[i]=dy[i-2]+dy[i-1];
    }
    printf("%d\n", dy[n]);
    return 0;
}
