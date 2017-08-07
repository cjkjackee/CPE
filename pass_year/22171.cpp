#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 50;
int L, R, C;
int Sz, Sx, Sy;
int Ez, Ex, Ey;
char maze[maxn][maxn][maxn];
int dist[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];
queue<int> q;
int bfs()
{
    while(!q.empty()) q.pop();
    q.push(Sz); q.push(Sx); q.push(Sy);
    dist[Sz][Sx][Sy] = 0;
    vis[Sz][Sx][Sy] = 1;        /// 表示已在队列中
    while(!q.empty())
    {
        int z = q.front(); q.pop();
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();

        if(z == Ez && x == Ex && y == Ey) return dist[z][x][y];

        if(z + 1 <= L && maze[z+1][x][y] != '#' && !vis[z+1][x][y])
        {
            q.push(z+1); q.push(x); q.push(y);
            dist[z+1][x][y] = dist[z][x][y] + 1;
            vis[z+1][x][y] = 1;
        }
        if(z - 1 >= 1 && maze[z-1][x][y] != '#' && !vis[z-1][x][y])
        {
            q.push(z-1); q.push(x); q.push(y);
            dist[z-1][x][y] = dist[z][x][y] + 1;
            vis[z-1][x][y] = 1;
        }
        if(x + 1 <= R && maze[z][x+1][y] != '#' && !vis[z][x+1][y])
        {
            q.push(z); q.push(x+1); q.push(y);
            dist[z][x+1][y] = dist[z][x][y] + 1;
            vis[z][x+1][y] = 1;
        }
        if(x - 1 >= 1 && maze[z][x-1][y] != '#' && !vis[z][x-1][y])
        {
            q.push(z); q.push(x-1); q.push(y);
            dist[z][x-1][y] = dist[z][x][y] + 1;
            vis[z][x-1][y] = 1;
        }
        if(y + 1 <= C && maze[z][x][y+1] != '#' && !vis[z][x][y+1])
        {
            q.push(z); q.push(x); q.push(y+1);
            dist[z][x][y+1] = dist[z][x][y] + 1;
            vis[z][x][y+1] = 1;
        }
        if(y - 1 >= 1 && maze[z][x][y-1] != '#' && !vis[z][x][y-1])
        {
            q.push(z); q.push(x); q.push(y-1);
            dist[z][x][y-1] = dist[z][x][y] + 1;
            vis[z][x][y-1] = 1;
        }
    }
    return 0;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    while(scanf("%d%d%d", &L, &R, &C) && L)
    {
        memset(dist, 0, sizeof(dist));
        memset(vis, 0, sizeof(vis));

        for(int i = 1; i <= L; i++)
        for(int j = 1; j <= R; j++) {
            scanf("%s", &maze[i][j][1]);
        }
        for(int i = 1; i <= L; i++)
        for(int j = 1; j <= R; j++)
        for(int k = 1; k <= C; k++)
            if(maze[i][j][k] == 'S') { Sz = i; Sx = j; Sy = k; }
            else if(maze[i][j][k] == 'E') { Ez = i; Ex = j; Ey = k; }

        int dist = bfs();
        if(dist) printf("Escaped in %d minute(s).\n", dist);
        else printf("Trapped!\n");
    }
    return 0;
}
