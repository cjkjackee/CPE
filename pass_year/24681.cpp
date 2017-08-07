#include<iostream>
#include <iomanip>

using namespace std;
int main(){

	int n[101],i=0;
	char out[3][15]={"DEFICIENT","PERFECT","ABUNDANT"};
	cin>>n[0];

	while(n[i]!=0){
		i++;
		cin>>n[i];
	}
	i=0;
	cout<<"PERFECTION OUTPUT"<<endl;
    while(n[i]!=0){
    	int sum=1;
    	for(int j=2;j<=n[i]/2;j++){
    		if(n[i]%j==0)sum+=j;
    	}
    	cout<<setw(5)<<n[i]<<"  ";
    	if(n[i]-sum<0)cout<<out[2]<<endl;
    	else if(n[i]-sum==0)cout<<out[1]<<endl;
    	else cout<<out[0]<<endl;

		i++;
    }
    cout<<"END OF OUTPUT"<<endl;

}
