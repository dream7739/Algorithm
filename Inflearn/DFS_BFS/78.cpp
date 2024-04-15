#include <iostream>
#include <vector>
using namespace std;

//78. 원더랜드 (크루스칼 MST: union & find)
int unf[10001];

struct Edge{
    int v1, v2, val;

    Edge(int a, int b, int c){
        v1 = a;
        v2 = b;
        val = c;
    }
    
    bool operator <(const Edge &b)const{
        return val < b.val;
    }
};

int Find(int v){
    if(v == unf[v]) return v;
    else return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a != b) unf[a] = b;
}

int main(){
    int n, m, a, b, c, res= 0;
    vector<Edge> Ed;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        unf[i] = i;
    }
    
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        Ed.push_back(Edge(a, b, c));
    }
    
    sort(Ed.begin(), Ed.end());
    
    for(int i = 0; i < m; i++){
        int fa = Find(Ed[i].v1);
        int fb = Find(Ed[i].v2);
        if(fa != fb){
            res += Ed[i].val;
            Union(fa, fb);
        }
    }
    cout << res;
    return 0;
}

