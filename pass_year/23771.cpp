#include <iostream>
#include <string>
#include <vector>
using namespace std;
long long int f(long long int n)
{
	long long int sum=1;
	for(long long int i=2;i<=n;i++){
		sum*=i;
	}
	return sum;
}
int main() {
    long long int case_number;
    cin>>case_number;
    long long int k=0,n;
    string s;
    while(k!=case_number){
    	cin>>s>>n;
    	vector<long long int> a;
    	vector<long long int> b;
    	char ans[20];
    	long long int length=s.size();
    	for(long long int i=1;i<=length;i++){
    		a.push_back(i);
    	}
    	for(long long int i=length-1;i>0;i--){
    		long long int d=f(i);
    		long long int c=n/d;
    		if(n%d!=0){
    			c++;
    		}
    		n%=d;
    		if(n==0){
    			n+=d;
    		}
    		b.push_back(a[c-1]);
    		a.erase(a.begin()+(c-1));
    	}
    	b.push_back(a[0]);
    	for(long long int i=0;i<length;i++){
    		ans[b[i]-1]=s[i];
    	}
    	cout<<"Case "<<k+1<<": ";
    	for(long long int i=0;i<length;i++){
    		cout<<ans[i];
    		ans[i]='\0';
    	}
    	cout<<endl;
    	a.clear();
    	b.clear();
    	k++;
    }
    return 0;
}
