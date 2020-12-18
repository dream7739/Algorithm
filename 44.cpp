

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n;

// 44. 마구간 정하기(결정 알고리즘)

int Count(int len, int x[]){
    int i, pos=x[1], cnt=1;
    for(i=2;i<=n;i++){
        if(x[i]-pos>=len){
            cnt++;
            pos=x[i];
        }
    }
    return cnt;
}

int main() {
    int m, i, lt=1, rt, mid,res;
    scanf("%d %d", &n, &m); //n: 마구간 좌표, m: 말 마리 수
    int *x = new int[n+1]; //n 범위가 큼 => 동적할당
    
    for(i=1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    sort(x+1,x+n+1); //배열 정렬
    rt=x[n]; //가장 큰 좌표를 rt
    
    //이분탐색
    while(lt<=rt){
        mid=(lt+rt)/2;
        if(Count(mid,x)>=m){
            res=mid;
            lt=mid+1;
        }
        else rt=mid-1;
    }
    printf("%d\n", res);
    delete[] x; //배열 할당 해제
    return 0;
}
 
