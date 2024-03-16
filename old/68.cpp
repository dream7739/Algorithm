#include<stdio.h>
#include<vector>
using namespace std;
vector<pair<int, int> > map[30];
int ch[30];
int n, cost=2147000000;

//68. 최소비용(DFS: 가중치 방향그래프 인접리스트)
void DFS(int L, int sum){
    int i;
    if(L==n){
        if(cost>sum){
            cost=sum;
        }
    }else{
        for(i=0;i<map[L].size();i++){
            //리스트기 때문에 0~map[L].size()까지 돌아야 함
            if(ch[map[L][i].first]==0){
                ch[map[L][i].first]=1;
                DFS(map[L][i].first, sum+map[L][i].second);
                ch[map[L][i].first]=0;
            }
        }
    }
}

int main(){
    int i, m, a, b, c;
    scanf("%d %d", &n, &m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d", &a, &b, &c);
        map[a].push_back(make_pair(b, c));
    }
    ch[1]=1;
    DFS(1,0);
    printf("%d\n", cost);
}


