#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    unsigned int const BigNumArray = 3;
    unsigned int loops, j = 1, maxDisc = 10000, i = 2, n, k, p;
    unsigned long long int f[10001][BigNumArray] = {0}, diff[BigNumArray] = {1, 0, 0};

    f[0][0] = 0, f[1][0] = 1;

    while(i <= maxDisc)
    {
        loops = j++ + 1;
        diff[0] += diff[0];

        for (k = 0; k < BigNumArray-1; k++)
        {
            diff[k+1] += diff[k+1];

            if (diff[k] >= 1000000000000000)
            {
                diff[k+1] += diff[k]/1000000000000000;
                diff[k] %= 1000000000000000;
            }
        }

        for(p = 1; p <= loops && i <= maxDisc; p++, i++)
        {
            f[i][0] = f[i-1][0] + diff[0];

            for (k = 0; k < BigNumArray-1; k++)
            {
                f[i][k+1] = f[i-1][k+1] + diff[k+1];

                if (f[i][k] >= 1000000000000000)
                {
                    f[i][k+1] += f[i][k]/1000000000000000;
                    f[i][k] %= 1000000000000000;
                }
            }
        }
    }

    while (cin >> n)
        if (f[n][2])
        {
            cout << f[n][2];
            cout << setw(15) << setfill('0') << f[n][1] << setw(15) << setfill('0') << f[n][0] << endl;
        }

        else if (f[n][1])
        {
            cout << f[n][1];
            cout << setw(15) << setfill('0') << f[n][0] << endl;
        }

        else
            cout << f[n][0] << endl;

    return 0;
}
