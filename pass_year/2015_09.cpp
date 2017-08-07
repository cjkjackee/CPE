#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int LIS[65536];
int ORI[65536];

int ceilIndex(int A[],int l,int r,int key)
{
    int m;
    while(r-l>1){
        m=l+(r-l)/2;
        (A[m]>=key?r:l)=m;
    }
    return r;
}
int lisLength(int A[],int size)
{
    int i,len;
    int *t=new int[size];
    memset(LIS,0,sizeof(t[0])*size);
    t[0]=A[0];
    len=1;
    for(i=1;i<size;i++){
        if(A[i]<t[0]){
            t[0]=A[i];
        }
        else if(A[i]>t[len-1]){
            t[len++]=A[i];
        }
        else{
            t[ceilIndex(t,-1,len-1,A[i])]=A[i];
        }
    }
    return len;
}
int main()
{
    int x,i;
    fill(LIS,LIS+65536,0);
    fill(ORI,ORI+65536,1);
    while(cin>>x){
        for(i=0;i<x;i++){
            cin>>ORI[i];
        }
        cout<<lisLength(ORI,x)<<endl;
    }
    return 0;
}
