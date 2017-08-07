#include<iostream>
#include<string>
using namespace std;

int main(void){
	string s,a,b="";
	int i,yn=0;
	cin>>s;
	while(s!="."){
		for(i=0;i<(s.length()/2);i++){
			a=s;
			a.resize(i+1);
			while(b!=s && b.length()<s.length()){
				b=b+a;
			}
			if(b==s){
				yn=1;
				break;
			}
			b="";
		}
		if(yn)
			cout<<(s.length())/(a.length())<<endl;
		else
			cout<<"1"<<endl;

		b="";
		yn=0;
		cin>>s;
	}

	return 0;
}
