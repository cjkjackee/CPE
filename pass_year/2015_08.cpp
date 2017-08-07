#include <iostream>
#include<cstring>
using namespace std;
int maxi = 5000;
int *arr;
void display(int arr[]){
    int ctr = 0;
    for (int i=0; i<maxi; i++){
         if (!ctr && arr[i])               ctr = 1;
         if(ctr)
            std::cout<<arr[i];
    }
    cout<<endl;
}
void climbingstairs(long long int n)
{
    int *a = new int[maxi];
    std::memset(a,0,maxi*sizeof(int));
    a[maxi-1] = 1;
     int *b = new int[maxi];
    std::memset(b,0,maxi*sizeof(int));
    b[maxi-1] = 2;
    int *c = new int[maxi];
    std::memset(c,0,maxi*sizeof(int));

    if(n==1){
         arr[maxi-1] = 1;

    }
    if(n==2){
        arr[maxi-1] = 2;

    }

    for(int j=3;j<=n;j++){
        int carry = 0;
        for (int i=maxi-1; i>=0; --i){
        c[i] = (a[i] + b[i]) + carry;
        carry = c[i]/10;
        c[i] %= 10;
        a[i]=b[i];
        b[i]=c[i];
        }


    }
    arr=c;

}
int main()
{
    int i;


    while(cin>>i && i<=100){
         arr = new int[maxi];
    std::memset(arr,0,maxi*sizeof(int));
        climbingstairs(i);display(arr);delete[] arr;
    }


    return 0;
}
