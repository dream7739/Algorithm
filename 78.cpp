#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int unf[10001];

//78. 원더랜드(Kruskal MST 알고리즘)
//최소비용 트리

struct Edge{
    int v1;
    int v2;
    int val;
    Edge(int a, int b, int c){
        v1=a;
        v2=b;
        val=c;
    }
    bool operator<(const Edge &b) const{
        return val<b.val;
    }
};

int Find(int v){
    if(v==unf[v]) return v;
    else return unf[v]=Find(unf[v]);
}

void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a!=b) unf[a]=b;
}

int main(){
    vector<Edge> Ed;
    int i, n, m, a, b, c, res=0;
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;i++){
        unf[i]=i;
    }
    for(i=1;i<=m;i++){
        scanf("%d %d %d", &a, &b, &c);
        Ed.push_back(Edge(a, b, c));
    }
    sort(Ed.begin(), Ed.end()); //가중치 오름차순 정렬
    for(i=0;i<m;i++){
        //두개 정점 Find
        int fa=Find(Ed[i].v1);
        int fb=Find(Ed[i].v2);
        if(fa!=fb){
            //다른 집합이면 가중치를 더하고
            res+=Ed[i].val;
            //Union한다
            Union(Ed[i].v1, Ed[i].v2);
        }
    }
    printf("%d\n", res);
    return 0;
}


