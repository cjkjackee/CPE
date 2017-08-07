
#include <string>
#include <iostream>
using namespace std;

int main()
{
    int d[100] = {1, 4, 7, 6, 5, 6, 3, 6, 9, 0, 1, 6, 3, 6, 5, 6, 7, 4, 9, 0};
    for (int i = 0; i < 20; i++)
        d[i+20] = d[i+40] = d[i+60] = d[i+80] = d[i];
    for (int i = 1; i < 100; i++)
        d[i] = (d[i] + d[i-1]) % 10;
    string num;
    while (cin >> num, num != "0")
    {
        int len = num.length();
        if (len > 1)
            cout << d[((num[len-2]-'0')*10+num[len-1]-'0'-1)%100] << endl;
        else cout << d[num[0]-'0'-1] << endl;
    }
    return 0;
}
