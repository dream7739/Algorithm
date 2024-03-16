#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int arr[31];
//55. 기차운행(stack)

int main(){
    int n, i, j=1, m;
    stack<int> s;
    scanf("%d", &n);
    vector<char> str; //push_back으로 넣으면 공간 생김
    for(i=1;i<=n;i++){
        scanf("%d", &m); //기차 읽기
        s.push(m);
        str.push_back('P');
        while(1){
            if(s.empty()) break; //값 없으면 break
            if(j==s.top()){
                //s.top()이랑 j랑 맞으면 계속 꺼냄
                s.pop();
                j++;
                str.push_back('O');
            }
            else break; //같지 않으면 넘어감
        }
    }
    
    if(!s.empty()) printf("impossible");
    else {
        for(i=0;i<str.size();i++){
            printf("%c", str[i]);
        }
    }
    return 0;
}

