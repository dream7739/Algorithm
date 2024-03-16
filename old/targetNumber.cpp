#include <string>
#include <vector>

using namespace std;

int count=0,a[21],t,m;

void DFS(int L, int sum){
    if(L==m+1){
        if(sum==t) {
            count++;
            return;
        }
    }else{
        DFS(L+1,sum-a[L]);
        DFS(L+1,sum+a[L]);
    }
}

int solution(vector<int> numbers, int target) {
    m=numbers.size();
    t=target;
    for(int i=1;i<=m;i++){
        a[i]=numbers[i-1];
    }
    DFS(1,0);
    return count;
}
