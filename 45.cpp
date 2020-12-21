

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 45. 공주 구하기(조세퍼스)

int main() {
    int n, k, pos=0, bp=0, cnt=0, i;  //n: 왕자, k: 특정수, bp: 1의 개수 n-1일 시 break, cnt 특정수 만족 check
    scanf("%d %d", &n, &k); //입력
    vector<int> prince(n+1); //1~n
    while(1){
        //bp=n-1이면 break
        pos++;
        if(pos>n) pos=1;
        if(prince[pos]==0){
            cnt++;
            if(cnt==k){
                //왕자 out
                prince[pos]=1;
                cnt=0;
                bp++; //7명 out시켜야 함
            }
        }
        if(bp==n-1) break;
    }
    
    //최종 출력
    for(i=1;i<=n;i++){
        if(prince[i]==0){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
 
