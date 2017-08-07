#include <iostream>
using namespace std;

int main()
{
    int t,m,n,q;
    cin>>t;
    while(t--)
    {
        cin>>m>>n>>q;
        char ch[102][102]={'\0'};//初始
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>ch[i][j];
            }
        }
        cout<<m<<" "<<n<<" "<<q<<endl;
        while(q--)
        {
            int r=0,c=0;
            cin>>r>>c;
            char center=ch[r][c];
            int ans=1;
            for(int k=3;k>=0;k+=2)//邊長
            {
                for(int i=0;i<k;i++)//從中心左上角開始跑k*k個字元
                {
                    for(int j=0;j<k;j++)
                    {
                        if(ch[r-((k-1)/2)+i][c-((k-1)/2)+j]!=center)
                        {
                            i=k;
                            ans=k-2;k=-3;
                            break;
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
