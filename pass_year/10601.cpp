#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
char g[305][305];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int x, y, s, tx, ty, ts;
int main() {
    int testcase;
    int n, m;
    int i, j;
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)
            scanf("%s", &g[i]);
        int sx, sy, ex, ey;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(g[i][j] == 'S')
                    sx = i, sy = j;
                if(g[i][j] == 'E')
                    ex = i, ey = j;
            }
        }
        int dp[305][305][3] = {};//1,2,3
        queue<int> X, Y, S;
        for(i = 0; i < 4; i++) {
            tx = sx+dx[i], ty = sy+dy[i];
            if(tx < 0 || ty < 0 || tx >= n || ty >= m)
                continue;
            if(g[tx][ty] == '#')    continue;
            dp[tx][ty][0] = 1;
            X.push(tx), Y.push(ty), S.push(0);
        }
        while(!X.empty()) {
            x = X.front(), X.pop();
            y = Y.front(), Y.pop();
            s = S.front(), S.pop();
            if(s == 0)  ts = 1;//step2
            if(s == 1)  ts = 2;//step3
            if(s == 2)  ts = 0;//step1
            for(i = 0; i < 4; i++) {
                int err = 0;
                tx = x, ty = y;
                for(j = 0; j <= ts; j++) {
                    tx += dx[i], ty += dy[i];
                    if(tx < 0 || ty < 0 || tx >= n || ty >= m) {
                        err = 1;
                        continue;
                    }
                    if(g[tx][ty] == '#')
                        err = 1;
                }
                if(err == 0) {
                    if(dp[tx][ty][ts] == 0) {
                        X.push(tx), Y.push(ty), S.push(ts);
                        dp[tx][ty][ts] = dp[x][y][s]+1;
                    }
                }
            }

        }
        int ret = 0xffff;
        for(i = 0; i < 3; i++)
            if(dp[ex][ey][i])
                ret = min(ret, dp[ex][ey][i]);
        if(ret != 0xffff)
            printf("%d\n", ret);
        else
            puts("NO");
    }
    return 0;
}
