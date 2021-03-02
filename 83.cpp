#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int a[10], ch[10];
//83. 복면산
//DEMNORSY 순서대로
int send(){
    //S=6 E=1 N=3 D=0
    return a[6]*1000+a[1]*100+a[3]*10+a[0];
}
int more(){
    //M=2 O=4 R=5 E=1
    return a[2]*1000+a[4]*100+a[5]*10+a[1];
}
int money(){
    //M=2 O=4 N=3 E=1 Y=7
    return a[2]*10000+a[4]*1000+a[3]*100+a[1]*10+a[7];
}

void DFS(int L){
    if(L==8){
        if(send()+more()==money()){
            if(a[6]==0 || a[2]==0) return;
            printf("  %d %d %d %d\n", a[6],a[1],a[3],a[0]);
            printf("+ %d %d %d %d\n", a[2],a[4],a[5],a[1]);
            printf("--------------\n");
            printf("%d %d %d %d %d\n", a[2],a[4],a[3],a[1],a[7]);
        }
    }else{
        for(int i=0;i<10;i++){
            if(ch[i]==0){
                a[L]=i;
                ch[i]=1;
                DFS(L+1);
                ch[i]=0;
            }
        }
    }
}


int main(){
    DFS(0);
    return 0;
}
