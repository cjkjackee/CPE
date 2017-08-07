#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

long long drawer [70][70][2];

long long dp(int n, int s, bool lock)
{
    if (n==1)
    {
        if (s==0 && lock==1)
            return 1;
        else if (s==0 && lock==0)
            return 2;
        else if (s==1 && lock==1)
            return 1;
        else
            return 0;
    }

    if (n<s)
        return 0;
    else if (n==s && lock==0)
        return 0;
    else if (drawer[n][s][lock]!=-1)
        return drawer[n][s][lock];
    else if (lock)
        drawer[n][s][lock] = dp(n-1,s-1,1) + dp(n-1,s,0);
    else
        drawer[n][s][lock] = dp(n-1,s,1) + dp(n-1,s,0);

    return drawer[n][s][lock];
}


int main ()
{
    int n, s;

    // init
    n = 0;
    s = 0;
    memset(drawer, -1, sizeof(drawer));

    while(1)
    {
        cin >> n;
        cin >> s;

        if (n<0 && s<0)
            break;

        cout << dp(n,s,1) << endl;
    }

    return 0;
}
