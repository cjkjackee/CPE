#include <iostream>

using namespace std;

int rev (int a)
{
    int b=0;
    while(a>=10)
    {
        b+=a%10;
        a/=10;
        b*=10;
    }
    return (b+=a,b);
}

int pal (int a,int c)
{
    return a==rev(a)?(cout<<c<<" ",a):pal(a+rev(a),++c);
}

int main()
{
    int a;
    while(cin>>a)
    {
        for(int i=0;i<a;i++)
        {
            int b,c=0;cin>>b;
            cout<<pal(b,c)<<endl;
        }
    }
    return 0;
}
