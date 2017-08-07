#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main()
{
    int data[1000];
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        for(int i=0; i<n; i++)
            cin >> data[i];
        std::sort(data,data+n);
        /*for(int i=0; i<n; i++)
            cout << " " << data[i];*/
        bool found = false;
        int a,b,c,d;
        int ans=0;
        for(d=n-1; d>=0 && !found; d--)
        {
            for(a=0; a<n && !found; a++)
            {
                if(a==d)
                    continue;
                for(b=a+1; b<n && !found; b++)
                {
                    if(b==d)
                        continue;
                    for(c=b+1; c<n && !found; c++)
                    {
                        if(c==d)
                            continue;
                        if(data[a]+data[b]+data[c] == data[d])
                        {
                            found = true;
                            ans = data[d];
                            //cout << "found " << data[d] << endl;
                        }
                    }
                }
            }
        }

        if(found)
            cout << ans << endl;
        else
            cout << "no solution" << endl;
    }
}
