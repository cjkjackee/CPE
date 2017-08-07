#include<iostream>
#include<list>
using namespace std;
int N;
int simulation(int m)
{
    list<int> num;

    for(int i=1;i<=N;i++)
    {
        num.push_back(i);
    }

    while(num.size()>1)
    {
        num.pop_front();
        for(int i=1;i<m;i++)
        {
            num.push_back(num.front());
            num.pop_front();
        }
    }

    return num.front();
}

int main()
{
    int region;
    while(!(cin>>N).eof())
    {
        if(N==0)
            return 0;
        int m=1;
        while(1)
        {
            region=simulation(m);
            if(region==13)
            {
                break;
            }
            m++;
        }
        cout<<m<<endl;

    }
}
