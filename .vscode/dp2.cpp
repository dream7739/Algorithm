#include <stdio.h>
#include <algorithm>
using namespace std;
int dy[101];
int n;
//DP2. 네트워크 선 자르기(Top-Down)

int DFS(int n)
{
    if (dy[n] > 0)
        return dy[n];
    if (n == 1 || n == 2)
        return n;
    else
        return dy[n] = DFS(n - 2) + DFS(n - 1);
}

int main()
{
    scanf("%d", &n);
    printf("%d\n", DFS(n));
    return 0;
}
