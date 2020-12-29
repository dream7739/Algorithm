#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[701][701], dy[701][701];

// 51. 영지선택 Large(DP)
int main() {
    int h, w, n, m, i, j, tmp, max=-2147000000;
    scanf("%d %d", &h, &w); //전체 땅
    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            scanf("%d", &a[i][j]);
            dy[i][j]=dy[i-1][j]+dy[i][j-1]-dy[i-1][j-1]+a[i][j];
            //해당 좌표의 왼, 위,왼쪽에서 위쪽을 뺀 후 해당 좌표값을 더해서 dy를 만듬
        }
    }
    scanf("%d %d", &n, &m); //받을 땅
    for(i=n;i<=h;i++){
        for(j=m;j<=w;j++){
            tmp=dy[i][j]-dy[i-n][j]-dy[i][j-m]+dy[i-n][j-m];
            if(tmp>max) max=tmp;
        }
    }
    printf("%d\n", max);
    return 0;
}
 
