#include<iostream>
#include<cstdlib>
#include<cstdio>
int main()
{
    int TC;
    scanf("%d",&TC);
    for(int r=0; r<TC; r++)
    {
        int n;
        scanf("%d",&n);
        int s[n];
        for(int i=0; i<n; i++)
            scanf("%d",&s[i]);

        int min, temp = 0;
        for(int j=0; j<n; j++)
        {
            temp+=abs(s[j]-s[0]);
        }
        min = temp;
        for(int i=1; i<n; i++)
        {
            temp = 0;
            for(int j=0; j<n; j++)
            {
                temp+=abs(s[j]-s[i]);
            }
            if(temp<min)
                min = temp;
        }
        printf("%d\n",min);
    }
}
