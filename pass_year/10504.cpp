#include <stdio.h>
#include <string.h>

int k, n;
char sb[35];
int s[35];
int ss[10];
int out[35];
int judge;
int d[8][3] = {{0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1}, {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};

void dfs(int num)
{
    if (judge == 1)
    return;
    if (num == n)
    {
    if (out[0] == out[num] && out[1] == out[num + 1])
    {
        judge = 1;
    }
    return;
    }
    for (int i = 0; i < 8; i ++)
    {
    if (s[num] == ss[i] && (num == 0 || out[num] == d[i][0] && out[num + 1] == d[i][1]))
    {
        if (num == 0)
        {
        out[num] = d[i][0];
        out[num + 1] = d[i][1];
        }
        out[num + 2] = d[i][2];
        dfs(num + 1);
    }
    }
}
int main()
{
    while (scanf("%d%d%s", &k, &n, sb) != EOF)
    {
    judge = 0;
    memset(out, 0, sizeof(out));
    for (int i = 0; i < n; i ++)
    {
        s[i] = sb[i] - '0';
    }
    for (int i = 0; i < 8; i ++)
    {
        ss[i] = k % 2;
        k /= 2;
    }
    dfs(0);
    if (judge)
        printf("REACHABLE\n");
    else
        printf("GARDEN OF EDEN\n");
    }
    return 0;
}
