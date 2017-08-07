#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int i, j, T;
    //freopen("test.txt", "r", stdin);
    while(scanf("%d", &T) == 1 && T){
        double num[1000], sum = 0;
        for(i = 0; i < T; i++){
            scanf("%lf", &num[i]);
            sum += num[i];
        }
        double avg = sum/T, s1 = 0, s2 = 0;
        for(i = 0; i < T; i++){
            double dif = (double) (int)((num[i]-avg)*100.0)/100.0;
            if(num[i] > avg)
                s1 += dif;
            if(num[i] < avg)
                s2 += -dif;
        }
        if(s1 > s2)
            printf("$%.2lf\n", s1);
        else
            printf("$%.2lf\n", s2);
    }
    return 0;
}
