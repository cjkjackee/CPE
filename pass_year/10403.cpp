#include<stdio.h>
int main(){
    int t,n,k,a,b,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        k=n;
        a=b=0;
        while(k){
            if(k%2) a++;
            k/=2;
        }
        while(n){
            k=n%10;
            while(k){
                if(k%2) b++;
                k/=2;
            }
            n/=10;
        }
        printf("%d %d\n",a,b);
    }
}
