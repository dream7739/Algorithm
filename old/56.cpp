#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//56. 스택활용 재귀
void recur(int x){
    if(x==0) return; //종료지점
    else {
        //종료지점이 아닐 때
        recur(x-1);
        printf("%d ", x);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    recur(n);
    return 0;
}
