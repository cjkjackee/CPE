
#include<iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		int x=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(n==i*i*i-j*j*j)
				{
					cout<<i<<" "<<j<<endl;
					x=1;
					break;
				}
			}
			if(x==1)
			{
				break;
			}

		}
		if(x==0)
		cout<<"No solution"<<endl;
	}

}
