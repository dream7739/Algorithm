#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int> > hs;
vector<pair<int, int> > pz;
int ch[20], m, res=2147000000, dis, sum=0;


//86. 피자 배달 거리(DFS)
void DFS(int L, int s){
    if(L==m){
        sum=0;
        for(int i=0;i<hs.size();i++){
            int x1=hs[i].first;
            int y1=hs[i].second;
            dis=2147000000;
            for(int j=0;j<m;j++){
                int x2=pz[ch[j]].first;
                int y2=pz[ch[j]].second;
                dis=min(dis, abs(x1-x2)+abs(y1-y2));
            }
            sum=sum+dis;
        }
        if(sum<res)res=sum;
    }
    else{
        for(int i=s;i<pz.size();i++){
            ch[L]=i;
            DFS(L+1, i+1);
        }
    }
}

int main(){
    int n, a;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>> a;
            if(a==1) hs.push_back(make_pair(i, j)); //집
            else if(a==2) pz.push_back(make_pair(i, j)); //피자가게
        }
    }
    DFS(0, 0);
    cout<<res;
    return 0;
}
