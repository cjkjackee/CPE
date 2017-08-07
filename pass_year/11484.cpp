#include<iostream>
using namespace std;

int main(void){
	int n,e,f,c,i,eb,cb=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>e>>f>>c;
		eb=e+f;
		while((eb/c)!=0){
			cb+=(eb/c);
			eb=(eb%c)+eb/c;
		}
		cout<<cb<<endl;
		cb=0;
	}

	return 0;
}
