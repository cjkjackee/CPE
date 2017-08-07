#include <iostream>
using namespace std;

int main ()
{
    int n;
    int p;
    int ans=0;

    while (1)
    {
        cin >> n;
        ans = 0;
        p = 2;

        if (!n)
            break;

        for (int i=n;i>0;--i)
        {
            while ((p!=2 && p!=3 && p!=5 && p!=7) && (p%2==0 || p%3==0 || p%5==0 || p%7==0))
                ++p;
            ans = (ans+p)%i;
            cout << ans << endl;
            //cout << p << endl;
            ++p;
        }
        cout << ans << endl;
    }

    return 0;
}
