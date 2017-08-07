#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
const int kMaxn(57);

bool cmp(const string &a,const string &b)
{
    return (a+b>b+a);
}

int main()
{
    int n;
    while(cin>>n && n)
    {
        string r[kMaxn];
        for(int i=1;i<=n;i++)
            cin>>r[i];

        sort(r+1,r+n+1,cmp);

        for(int i=1;i<=n;i++)
            cout<<r[i];
        cout<<endl;
    }

    return 0;
}
