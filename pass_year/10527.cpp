#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int>  v;
    int i;
    while (cin>>i){
        v.push_back(i);
        stable_sort(v.begin() , v.end());
        //cout<<v[0]<<endl;
        if(v.size()%2==0){
            int tmp1 = v[v.size()/2];
            int tmp2 = v[v.size()/2-1];
            cout<<(tmp1+tmp2)/2<<endl;
        }else{
            int tmp1 = v[v.size()/2];
            cout<<tmp1<<endl;
        }
    }
    return 0;
}
