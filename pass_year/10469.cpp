#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, num[101], total = 0;
    while(scanf("%d", &n) == 1){
        int V[20001]={}, judge = 1;
        for(int i = 0; i < n; i++){
            scanf("%d", &num[i]);
            if(num[i] <= 0) judge = 0;
            if(i && num[i-1] >= num[i])  judge = 0;
        }
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(V[num[i]+num[j]])    judge = 0;
                V[num[i]+num[j]] = 1;
            }
        }
        if(judge)
            printf("Case #%d: It is a B2-Sequence.\n", ++total);
        else
            printf("Case #%d: It is not a B2-Sequence.\n", ++total);
        puts("");
    }
    return 0;
}
