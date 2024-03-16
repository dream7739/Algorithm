#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//75. 최대수입 스케쥴(priority_queue 응용)

struct Data{
    int money;
    int when;
    Data(int a, int b){
        money=a;
        when=b;
    }
    //정렬기준
    bool operator<(const Data &b)const{
        return when>b.when; //앞에게 큰값을 가진다 => 내림차순 정렬
    }
};

int main(){
    int n, i, j, a, b, res=0, max=-2147000000;
    vector<Data> T;
    priority_queue<int> pQ;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        scanf("%d %d", &a, &b);
        T.push_back(Data(a, b));
        if(b>max) max=b; //마지막 강연할 날짜 구함
    }
    sort(T.begin(), T.end()); //operator 기준에 따라 정렬
    j=0;
    for(i=max;i>=1;i--){
        for( ; j<n; j++){
            if(T[j].when<i) break;
            pQ.push(T[j].money); //날짜가 크거나 같은것만 push
        }
        if(!pQ.empty()){
            res+=pQ.top();
            pQ.pop();
        }
    }
    printf("%d\n", res);
    return 0;
}


