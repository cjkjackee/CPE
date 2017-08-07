#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        while(n--)
        {
            int a,div=9;cin>>a;
            vector<int>ans;
            if(a==1)ans.push_back(1);
            while(a!=1 && div !=1)
                if(a%div==0)
                {
                    ans.push_back(div);
                    a/=div;
                }
                else
                    div--;
            if(a!=1)
                cout<<-1;
            else
                for(int i=static_cast<int>(ans.size())-1;i>=0;i--)
                    cout<<ans[i];
            cout<<endl;
        }
    }
    return 0;
}

