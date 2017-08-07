#include <iostream>
using namespace std;
#define mod 1000000009
long long mpow(long long m, long long n)
{
    long long tmp = 1;
    while(n)
    {
        if(n & 1)
        {
            tmp *= m;
            tmp %= mod;
        }
        m = (m * m) % mod;
        n >>= 1;
    }
    return tmp;
}
int main()
{
    long long n;
    while(cin >> n)
        cout << (mpow(3,n)-2) % mod << endl;
}
