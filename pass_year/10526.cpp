#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char a[1000],b[1000];
    while(cin>>a && cin>>b)
    {
        int A[1000]={0},B[1000]={0},C[1000]={0},i,o;
        for(i=0;i<(int)strlen(a);i++)
            A[i]=a[strlen(a)-i-1]-48;
        for(i=0;i<(int)strlen(b);i++)
            B[i]=b[strlen(b)-i-1]-48;
        for(i=0;i<1000;i++)
            for(o=0;o<1000;o++)
                if(i+o<1000)
                    C[i+o]+=A[i]*B[o];
        for(i=0;i<999;i++)
        {
            C[i+1]+=C[i]/10;
            C[i]%=10;
        }
        for(i=999;C[i]==0&&i>0;i--);
        for(o=i;o>=0;o--)
            cout<<C[o];
        cout<<endl;
    }
    return 0;
}
