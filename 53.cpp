#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
//int stack[100], top=-1; //++해서 push

//53. K진수 출력
//스택 자료구조 직접 구현

//void push(int x){
//    stack[++top]=x;
//}
//int pop(){
//    return stack[top--];
//}

int main() {
    int n, k;
    char str[20]="0123456789ABCDEF"; //수 변환
    scanf("%d %d", &n, &k); //n이라는 수를 k진수화
    stack<int> s;
    while(n>0){
        s.push(n%k);
        n/=k;
    }
    
//    while(top!=-1){
//        printf("%c", str[pop()]);
//    }
    while(!s.empty()){
        printf("%c", str[s.top()]); //s.top는 참조만, s.pop은 직접 뺌
        s.pop();
    }
    printf("\n");
    return 0;
}
 
