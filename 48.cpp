#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[10][10];


// 48. 각 행의 평균과 가장 가까운 값
int main() {
    int i, j, sum, avg, min, tmp, res;
    for(i=1;i<=9;i++){
        sum=0;
        for(j=1;j<=9;j++){
            scanf("%d", &a[i][j]);
            sum+=a[i][j];
        }
        avg = (sum/9.0)+0.5; //9로 나누면 소숫점이 생기지 않음 (실수/정수 => 실수), +0.5해서 반올림
        printf("%d ", avg);
        min=2147000000;
        for(j=1;j<=9;j++){
            tmp=abs(a[i][j]-avg);
            if(tmp<min){
                min=tmp;
                res=a[i][j];
            }
            else if(tmp==min){
                //평균과의 거리가 같은 값이 나왔을 땐 큰 값
                if(a[i][j]>res) res=a[i][j];
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
 
