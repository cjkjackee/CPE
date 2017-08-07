#include <iostream>
#include <bitset>
using namespace std;

int main ()
{
    int n;
    bitset<30> s1, s2;
    int s1_n, s2_n;

    // init
    n = 0;

    cin >> n;
    for (int x=0;x<n;++x)
    {
        cin >> s1;
        cin >> s2;

        s1_n = s1.to_ulong();
        s2_n = s2.to_ulong();

        while(s2_n!=0)
        {
            int tmp = s2_n;
            s2_n = s1_n % s2_n;
            s1_n = tmp;
        }

        cout << "Pair #" << x+1;
        if (s2_n==0 && s1_n!=1)
            cout << ": All you need is love!" << endl;
        else
            cout << ": Love is not all you need!" << endl;
    }
    return 0;
}
