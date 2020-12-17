

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[1001], n;
// 43. 뮤직비디오(결정 알고리즘)

//필요 DVD 리턴
int Count(int s){
    int i, cnt=1, sum=0;
    for(i=1;i<=n;i++){
        if(sum+a[i]>s){
            cnt++; //DVD추가
            sum=a[i]; //초과된 DVD부터 sum count
        }
        else{
            sum+=a[i];
        }
    }
    return cnt;
}


int main() {
    int m, i, lt=1, rt=0, mid, res;
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;i++){
        scanf("%d", &a[i]);
        rt=rt+a[i];
    }
    while(lt<=rt){
        mid=(lt+rt)/2; //dvd한 개의 최소 용량
        if(Count(mid)<=m){
            res=mid;
            rt=mid-1;
        }else{
            lt=mid+1;
        }
    }
    printf("%d\n",res);
    return 0;
}
 
