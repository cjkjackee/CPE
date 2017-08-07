#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
    char s[1000]={0},t[1000]={0};
    int i,j,r=0;
    int slen,tlen;
    while(cin>>s>>t){
        slen=strlen(s);
        tlen=strlen(t);
        for(i=0,j=0;i<slen,j<tlen;j++){
            if(s[i]==t[j]){
                i++;
                j=j;
                r++;
            }
        }
        if(r==slen){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        r=0;
    }
    return 0;
}
