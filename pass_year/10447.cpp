#include<iostream>
using namespace std;
int main(void){
	long long int tx,ty,sx,sy;
	long long int n,i,count=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>sx>>sy>>tx>>ty;
		while((sx+sy)!=(tx+ty)){
			count+=(sx+sy)+2;
			sx++;
		}
		count+=(tx-sx);
		cout<<"Case "<<i<<": "<<count<<endl;
		count=0;
	}

	return 0;
}
