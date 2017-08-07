#include <iostream>

using namespace std;

bool prime(int n)
{
	for(int i=2;i*i<=n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}

int main() {
    int n;
    int a[3500];
    for(int i=2,j=0;j<3500;i++){
    	if(prime(i)){
    		a[j++]=i;
    	}
    }
    while(cin>>n, n){
    	int r=0;
    	for(int i=1,j=n-2;i<n;i++){
    		r=(r+a[j])%(i+1);
    		j--;
    	}
    	cout<<r+1<<endl;
    }
    return 0;
}
