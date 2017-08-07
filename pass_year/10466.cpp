#include <stdio.h>
int main()
{
    int i, T, n, total = 0,cost[36], time;
    scanf("%d", &T);
    while(T--){
        for(i = 0; i < 36; i++)
            scanf("%d", &cost[i]);
        scanf("%d", &time);
        printf("Case %d:\n", ++total);
        while(time--){
            scanf("%d", &n);
            int Min = 1e9, sum[37]={0};
            for(int i = 2; i <= 36; i++){
                int temp = n;
                while(temp){
                    sum[i] += cost[temp%i];
                    temp /= i;
                }
                if(sum[i] < Min)    Min = sum[i];
            }
            printf("Cheapest base(s) for number %d:", n);
            for(int i = 2; i <= 36; i++)
                if(Min == sum[i])   printf(" %d", i);
            puts("");
        }
        if(T)   puts("");
    }
    return 0;
}
