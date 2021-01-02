#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//54. 올바른 괄호(stack)
int main(){
    int i, flag=1;
    char a[50];
    stack<char> s;
    scanf("%s", &a);
    
    for(i=0;a[i]!='\0';i++){
        if(a[i]=='('){
            s.push(a[i]);
        }else{
            //ex (()))
            if(s.empty()){
                printf("NO\n");
                flag=0;
                break;
            }
            else s.pop();
        }
    }
    //break하면 여기로 넘어오기 때문에 실행안되게 flag로 막아야함
    if(flag && s.empty()) printf("YES\n");
    else if(flag==1 && !s.empty()) printf("NO\n");
    return 0;
}

