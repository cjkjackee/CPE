#include <cstdlib>
#include <iostream>
using namespace std;
int main(void){
int n,left,total=0;
    while(cin>>n){
        total=n;
    for(;;n>0){
        left=n%3;
        n=n-left;
        n=n/3;
        total+=n;
        n=n+left;
        if(n<3){
            if(n==2){
                total++;
            }
            break;}
    }
    cout<<total<<'\n';
    total=0;
    }
}
