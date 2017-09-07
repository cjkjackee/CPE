#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int currency[6] = {1,2,4,10,20,40};
vector<int> recive, coin, own;
int sum;
int cost;

void shop();
int total_coin(int );

int main ()
{
    int a,b;

    own.assign(1,0);
    recive.assign(2001,10000);
    recive[0] = 0;
    shop();
    coin.assign(6,0);
    while(1)
    {
        sum = 0;
        for (int i=0;i<6;++i)
        {
            cin >> coin[i];
            sum += currency[i]*coin[i];
        }
        if (!sum)
            break;
        scanf("%d.%d\n", &a,&b );
        cost = a;
        cost *= 100;
        cost += b;
        cost /= 5;

        own.resize(1);
        own.resize(sum+1,10000);

        cout << setw(3) << total_coin(cost) << endl;
    }
    return 0;
}

int total_coin (int money)
{
    int ans = 10000;

    for (int i=0;i<6;++i)
    {
        for (int x=sum;x>=0;--x)
        {
            for (int y=1;y<=coin[i];++y)
            {
                if (x-currency[i]*y<0)
                    break;
                own[x] = min (own[x],own[x-currency[i]*y]+y);
            }
        }
    }

    for (int i=money;i<own.size();++i)
        ans = min(ans,own[i]+recive[i-money]);

    return ans;
}

void shop ()
{
    for (int i=0;i<6;++i)
    {
        for (int x=1;x<recive.size();++x)
        {
            if (x>=currency[i])
                recive[x] = min(recive[x],recive[x-currency[i]]+1);
        }
    }
}
