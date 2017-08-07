#include<iostream>

using namespace std;

int main(){

    int n,k;

    while(cin>>n>>k){
        int ans=n;
        while(n>=k){
            int butt=n/k;
            ans+=butt;
            n=n%k+butt;
        }
        cout<<ans<<endl;
    }
}
