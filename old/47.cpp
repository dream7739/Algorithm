#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[60][60];
int dx[4]={-1, 0, 1, 0}; //시계 방향 행 변경
int dy[4]={0, 1, 0, -1}; //시계 방향 열 변경


// 47. 봉우리

int main() {
    int n, i, k, j, cnt=0, flag;
    scanf("%d", &n);
    //vector<vector<int> > a(n+2, vector<int>(n+2, 0));
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            flag=0;
            for(k=0;k<4;k++){
                if(a[i][j]<=a[i+dx[k]][j+dy[k]]){
                    flag=1;
                    break;
                }
            }
            if(!flag) cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
 
