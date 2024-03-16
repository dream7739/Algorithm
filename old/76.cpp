#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int dy[21][21];

//76. 이항계수(조합)(메모이제이션)
//nCr=n-1Cr-1 + n-1Cr
int DFS(int n, int r){
    if(dy[n][r]>0) return dy[n][r]; //미리 구해놓은 것이 있으면 구하지 않고 배열에 잇는 값을 쓴다
    if(n==r || r==0) return 1;
    else return dy[n][r]=DFS(n-1, r-1)+DFS(n-1, r);
}


int main(){
    int n, r;
    scanf("%d %d", &n, &r);
    printf("%d\n", DFS(n, r));
    return 0;
}


