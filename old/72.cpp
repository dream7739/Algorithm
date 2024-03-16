#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

//72. 공주구하기 (조세퍼스 : 큐를 이용하는 방법)
int main(){
    queue<int> Q;
    int n, k, i;
    scanf("%d %d", &n, &k); //왕자수, k번호
    for(i=1;i<=n;i++){
        Q.push(i);
    }
    int j=0;
    while(!Q.empty()){
        for(i=1;i<k;i++){
            Q.push(Q.front()); //가장 앞의 값 가장뒤에 push
            Q.pop(); //뒤에 넣은 후에 pop함
        }
        Q.pop(); //3외친 사람 pop함
        if(Q.size()==1){
            printf("%d\n", Q.front());
            Q.pop();
        }
    }
    return 0;
}


