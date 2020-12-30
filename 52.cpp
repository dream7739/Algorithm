#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[1501];

// 52. Ugly Numbers(3 point)
int main() {
    int n, i, p2, p3, p5, min=2147000000;
    scanf("%d",&n); //몇 번째 ugly number인지
    a[1]=1; //첫 번째 수는 1
    p2=p3=p5=1;
    
    for(i=2;i<=n;i++){
        if(a[p2]*2<a[p3]*3) min=a[p2]*2;
        else min=a[p3]*3;
        if(a[p5]*5<min) min=a[p5]*5; //둘 중에 min과 비교해서 작으면 min
        if(a[p2]*2==min) p2++; //p2가 min이면 ++
        if(a[p3]*3==min) p3++; //else if 아닌 이유는 동시에 min과 같은 값이면 둘 다 위치 이동
        if(a[p5]*5==min) p5++;
        a[i]=min;
    }
    
    printf("%d\n", a[n]);
    
    return 0;
}
 
