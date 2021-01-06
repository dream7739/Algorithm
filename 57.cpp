#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//57. 재귀함수 이진수 출력
void recur(int x){
    if(x==0){ return; }
    else {
        recur(x/2);
        printf("%d", x%2);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    recur(n);
    return 0;
}
