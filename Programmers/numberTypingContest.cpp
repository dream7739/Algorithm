#include <string>
#include <limits.h>
#include <vector>
using namespace std;

int cost[10][10] = {
        { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
        { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
        { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
        { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
        { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
        { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
        { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
        { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
        { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
        { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 }
};
int dp[100001][10][10];
int len;
string arr;

int DFS(int n, int l, int r){
    if(n == len) return 0;
    if(dp[n][l][r] != 0) return dp[n][l][r];
    
    int num = arr[n] - '0';
    int result = INT_MAX;
    
    //오른쪽 입력
    if(l != num){
        result = min(result, DFS(n+1, l, num) + cost[r][num]);
    }
    
    //왼쪽 입력
    if(r != num){
        result = min(result, DFS(n+1, num, r) + cost[l][num]);
    }
    
    return dp[n][l][r] = result;
}

int solution(string numbers) {
    int answer = 0;
    arr = numbers;
    len = numbers.length();
    answer = DFS(0, 4, 6);
    return answer;
}
