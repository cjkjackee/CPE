#include <iostream>

using namespace std;

int main()
{
    int n,N;
    cin>>n;
    while(n--)
    {
        cin>>N;
        float data[2][N];
        for(int i=0;i<N;i++)
        {
            float a,b;
            cin>>a>>b;
            data[0][i]=i+1;
            data[1][i]=b/a;
        }
        for(int i=1;i<N;i++)
            if(data[1][i]>data[1][i-1])
            {
                float temp1=data[0][i-1],temp2=data[1][i-1];
                data[0][i-1]=data[0][i],data[1][i-1]=data[1][i];
                data[0][i]=temp1,data[1][i]=temp2;
                i=i>1?i-2:0;
            }
        for(int i=0;i<N;i++)
            cout<<data[0][i]<<(i==(N-1)?"":" ");
        cout<<endl;
        if(n)
            cout<<endl;
    }
    return 0;
}
