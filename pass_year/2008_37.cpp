#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<iostream>
#include<stack>

using namespace std;

struct co
{
    char op;
    int integer;
    int type;
};

int main(void)
{

    char s[10000];

    while(cin.getline(s, 10000))
    {
        stack<co> mystack;
        if(s[0]=='.')
            break;
        int temp=0;
        int len=strlen(s);
        for(int i=0; i<len; i++)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='%')
            {
                co a;
                a.type=1;
                a.op=s[i];
                mystack.push(a);

            }
            else if(s[i]==' ')
            {
                //if(s[i-1]!='+' && s[i-1]!='-' && s[i-1]!='*' && s[i-1]!='/' && s[i-1]!='%')
                if('0'<=s[i-1] && s[i-1]<='9') //char a; isdigit(a)<=#include<ctype.h>
                {
                    co a;
                    a.type=2;
                    a.integer=temp;
                    mystack.push(a);
                    temp=0;     //�O�o�k�s

                    while(mystack.size()>=3)
                    {
                        co c, d, e;
                        e = mystack.top();
                        mystack.pop();
                        d = mystack.top();
                        mystack.pop();
                        c = mystack.top();
                        mystack.pop();

                        if(c.type==1 && d.type==2 && e.type==2)
                        {
                            if(c.op=='+')
                            {
                                co a;
                                a.type=2;
                                a.integer=d.integer + e.integer;
                                mystack.push(a);
                            }
                            else if(c.op=='-')
                            {
                                co a;
                                a.type=2;
                                a.integer=d.integer - e.integer;
                                mystack.push(a);

                            }
                            else if(c.op=='*')
                            {
                                co a;
                                a.type=2;
                                a.integer=d.integer * e.integer;
                                mystack.push(a);
                            }
                            else if(c.op=='/')
                            {
                                co a;
                                a.type=2;
                                a.integer=d.integer / e.integer;
                                mystack.push(a);
                            }
                            else if(c.op=='%')
                            {
                                co a;
                                a.type=2;
                                a.integer=d.integer % e.integer;
                                mystack.push(a);
                            }
                        }
                        else
                        {
                            mystack.push(c);
                            mystack.push(d);
                            mystack.push(e);
                            break;
                        }

                    }

                }
                continue;
            }
            else
            {
                int n;
                n=s[i]-'0';
                temp = n + temp*10;
            }
        }
        if(s[len-1]!=' ')
        {
            //if(s[i-1]!='+' && s[i-1]!='-' && s[i-1]!='*' && s[i-1]!='/' && s[i-1]!='%')
            if('0'<=s[len-1] && s[len-1]<='9') //char a; isdigit(a)<=#include<ctype.h>
            {
                co a;
                a.type=2;
                a.integer=temp;
                mystack.push(a);
                temp=0;

                while(mystack.size()>=3)
                {
                    co c, d, e;
                    e = mystack.top();
                    mystack.pop();
                    d = mystack.top();
                    mystack.pop();
                    c = mystack.top();
                    mystack.pop();

                    if(c.type==1 && d.type==2 && e.type==2)
                    {
                        if(c.op=='+')
                        {
                            co a;
                            a.type=2;
                            a.integer=d.integer + e.integer;
                            mystack.push(a);
                        }
                        else if(c.op=='-')
                        {
                            co a;
                            a.type=2;
                            a.integer=d.integer - e.integer;
                            mystack.push(a);

                        }
                        else if(c.op=='*')
                        {
                            co a;
                            a.type=2;
                            a.integer=d.integer * e.integer;
                            mystack.push(a);
                        }
                        else if(c.op=='/')
                        {
                            co a;
                            a.type=2;
                            a.integer=d.integer / e.integer;
                            mystack.push(a);
                        }
                        else if(c.op=='%')
                        {
                            co a;
                            a.type=2;
                            a.integer=d.integer % e.integer;
                            mystack.push(a);
                        }
                    }
                    else
                    {
                        mystack.push(c);
                        mystack.push(d);
                        mystack.push(e);
                        break;
                    }

                }

            }
        }
        if(mystack.size()==1 && mystack.top().type==2)
            cout<<mystack.top().integer<<endl;
        else
            cout<<"illegal"<<endl;
    }

    return 0;
}
