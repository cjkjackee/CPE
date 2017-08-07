#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

template <class T>
T gcd(T a, T b)
{
    if(b)
    {
        while((a %= b) && (b %= a));
        return a + b;
    }
}

// convert binary to decimal
long int b2d(string str)
{
    int len = str.size();

    long int dec=0;

    for(int i=0; i<len; i ++)
    {
        dec += (str[i] - '0') * pow(2, len - i - 1);
    }

    return dec;
}

int main()
{
    int num;

    cin >> num;

    for(int i=1; i<=num; i++)
    {
        long int n1=0,n2=0;
        string s1,s2;

        cin >> s1 >> s2;

        n1 = b2d(s1);
        n2 = b2d(s2);

        if(gcd(n1,n2)==1)
            cout << "Pair #" << i << ": Love is not all you need!" << endl;

        else
            cout << "Pair #" << i << ": All you need is love!" << endl;
    }

    return 0;
}
