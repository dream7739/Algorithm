#include <stdio.h>
#include <algorithm>
using namespace std;
int map[51][51];

//63. 인접 행렬
int main(){
    int n, m, i, j, a, b, c;
    scanf("%d %d", &n, &m); //정점, 간선개수
    for(i=1;i<=m;i++){
        scanf("%d %d %d", &a, &b, &c);
        map[a][b]=c;
        //무방향
        //map[b][a]=1;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

