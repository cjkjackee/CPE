#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int calculate(string s)
{

        int sign=1;
        int opt=0;
        int sum=0;
        int lastnum;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                int num = 0;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                //i--;
                if(opt == 0) lastnum = num;
                if(opt == 1) lastnum *= num;
                if(opt == 2) lastnum /= num;
            }
            if(s[i] == '+') {
                sum += sign * lastnum;
                opt = 0;
                sign = 1;
            }
            if(s[i] == '-'){
                sum += sign * lastnum;
                opt = 0;
                sign = -1;
            }
            if(s[i] == '*'){
                opt = 1;
            }
            if(s[i] == '/'){
                opt = 2;
            }
        }
        sum += sign * lastnum;
        return sum;
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

