#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        int num[50], Ans = 0;
        for(int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n-i-1; j++)
                if(num[j] > num[j+1]){
                    swap(num[j], num[j+1]);
                    Ans++;
                }
        printf("Optimal train swapping takes %d swaps.\n", Ans);
    }
    return 0;
}
