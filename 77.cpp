#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int unf[1001]; //1차원 배열로 트리형태 구현

//77. 친구인가(Disjoint-set : Union & find 알고리즘) 서로소 집합
int Find(int v){
    //연결된 루트노드가 리턴된다.
    if(v==unf[v]) return v;
    else return unf[v]=Find(unf[v]);
}

void Union(int a, int b){
    a=Find(a); //a의 집합번호를 리턴
    b=Find(b); //b의 집합번호를 리턴
    if(a!=b) unf[a]=b; //서로의 집합이 다르면 서로 합침
}

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m); //반 학생수 n, 숫자쌍 m
    for(int i=1;i<=n;i++){
        unf[i]=i; //초기화
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d", &a, &b);
        Union(a, b);
    }
    scanf("%d %d", &a, &b);
    a=Find(a);
    b=Find(b);
    if(a==b) printf("YES");
    else printf("NO");
    return 0;
}


