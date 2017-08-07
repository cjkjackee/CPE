#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int calculate(string s)
{

        int res = 0;
        stack<bool> mystack;
        mystack.push(true);
        mystack.push(true);
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == '+' || c == '(') mystack.push(mystack.top());
            if(c == '-') mystack.push(!mystack.top());
            if(c == ')') mystack.pop();
            if(isdigit(c)){
                int num = c - '0';
                int j = i + 1;
                while(j < s.size() && isdigit(s[j])){
                    num = num * 10 + s[j] - '0';
                    j++;
                }
                i = --j;
                if(mystack.top()) res += num;
                else res -= num;
                mystack.pop();
            }
        }
        return res;
}
int main()
{
    string n;
    int x=1;
    while(cin>>n){
        cout<<"case "<<x<<":"<<endl;
        cout<<calculate(n)<<endl;
        cout<<endl;
        x++;
    }
    return 0;
}
