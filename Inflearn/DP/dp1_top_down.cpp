#include <iostream>
using namespace std;

//1. 네트워크 선 자르기(Top-down)
int dp[50];

int DFS(int n){
    if(n == 1 || n == 2) return n;
    if(dp[n] > 0) return dp[n];
    return dp[n] = DFS(n-2) + DFS(n-1);
}
   
int main(){
    int n;
    cin >> n;
    
    cout << DFS(n);
    
    return 0;
}
