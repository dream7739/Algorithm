#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[2001];

// 46. 멀티태스킹(카카오 먹방 문제 변형)

int main() {
    int n, k, i, pos=0, bp=0, tot=0;
    scanf("%d", &n); //작업의 개수
    for(i=1;i<=n;i++){
        scanf("%d", &a[i]);
        tot+=a[i];
    }
    scanf("%d", &k); //정전 시간
    if(tot<=k){
        //정전 나기 전 일이 끝남
        printf("-1\n");
        return 0;
    }
    while(1){
        pos++;
        if(pos>n){
            pos=1; //배열1로 포지션 이동
        }
        if(a[pos]==0) continue; //무시하고 반복문 증가
        a[pos]--; //작업 1감소
        bp++; //1초 증가
        if(bp==k) break; //정전, pos까지 작업
    }
    while(1){
        pos++;
        if(pos>n){
            pos=1;
        }
        if(a[pos]!=0) break; //정전 후, 0이 아닌 다음 작업 찾음
    }
    
    printf("%d\n", pos);

    
    return 0;
}
 
