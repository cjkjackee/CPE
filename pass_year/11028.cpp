#include <iostream>

using namespace std;
bool prime (int n)
{
    if(n==0 || n==1) {return false;}
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int sum (int n)
{
    return (n<10)? n:n%10+sum(n/10);
}
int main()
{
    int n,t1,t2;
    int k=0;
    cin>>n;
    while(k!=n){
        int num=0;
        cin>>t1>>t2;
        for(int i=t1;i!=t2+1;i++){
            if(prime(i)){
                (prime(sum(i)))? num++ : num=num;
            }
        }
        cout<<num<<endl;
        k++;
    }
    return 0;
}
