#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int map[21][21], ch[21][21];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
//90. 라이온킹 심바(BFS)

struct Loc
{
    int x;
    int y;
    int dis;
    Loc(int a, int b, int c)
    {
        x = a;
        y = b;
        dis = c;
    }
    bool operator<(const Loc &bb) const
    {
        if (dis != bb.dis)
            return dis > bb.dis;
        if (x != bb.x)
            return x > bb.x;
        else
            return y > bb.y;
    }
};
struct Lion
{
    int x, y, s, ate;
    void sizeUp()
    {
        ate = 0;
        s++;
    }
};

int main()
{
    int n, i, j, res = 0;
    priority_queue<Loc> Q;
    Lion simba;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 9)
            {
                simba.x = i;
                simba.y = j;
                map[i][j] = 0;
            }
        }
    }
    Q.push(Loc(simba.x, simba.y, 0));
    simba.s = 2;
    simba.ate = 0;
    while (!Q.empty())
    {
        Loc tmp = Q.top();
        Q.pop();
        int x = tmp.x;
        int y = tmp.y;
        int z = tmp.dis;
        if (map[x][y] != 0 && map[x][y] < simba.s)
        {
            simba.x = x;
            simba.y = y;
            simba.ate++;
            if (simba.ate >= simba.s) simba.sizeUp();
            map[x][y] = 0;
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    ch[i][j] = 0;
                }
            }
            while (!Q.empty()) Q.pop();
            res = tmp.dis; //tmp.dis = 최초 출발시부터 현재까지 잡아먹은 토끼까지의 거리
        }
        for (i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > n || map[xx][yy] > simba.s || ch[xx][yy] > 0) continue;
            Q.push(Loc(xx, yy, z + 1));
            ch[xx][yy] = 1;
        }
    }
    printf("%d\n", res);
    return 0;
}