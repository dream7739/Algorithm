#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, res=-2147000000;
vector<int> T, P; //날짜 & 수익
//84. 휴가

void DFS(int L, int sum){
    if(L==n+1){
        if(sum>res) res=sum;
    }else{
        if(L+T[L]<=n+1) DFS(L+T[L], sum+P[L]); //n+1일까지 마무리 가능 => 상담 한다
        DFS(L+1, sum); //안하고 다음날로 넘어감
    }
}

int main(){
    int a, b;
    scanf("%d", &n); //상담 횟수
    T.push_back(0);
    P.push_back(0);
    for(int i=0;i<n;i++){
        scanf("%d %d", &a, &b);
        T.push_back(a);
        P.push_back(b);
    }
    DFS(1,0);
    printf("%d\n", res);
    return 0;
}
