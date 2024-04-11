#include <iostream>
using namespace std;

//76. 이항계수
int dy[21][21];

int DFS(int n, int r){
    if(dy[n][r] > 0) return dy[n][r];
    if(n == r || r == 0) return 1;
    else return dy[n][r] = DFS(n-1, r-1) + DFS(n-1, r);
}

int main(){
    int n, r;
    cin >> n >> r; //n개 중에서 r개를 뽑는다
    cout << DFS(n, r);
    return 0;
}
