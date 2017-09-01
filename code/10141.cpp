#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main ()
{
    string s;
    long long n1, n2;
    long long ans;
    deque<string> prefix;
    vector<long long> stack;

    while(getline(cin,s))
    {
        prefix.clear();
        stack.clear();

        if (s==".")
            break;

        stringstream ss;
        ss << s;
        while (ss >> s)
            prefix.push_back(s);

        while(!prefix.empty())
        {
            s = prefix.back();
            prefix.pop_back();
            if (s=="+" || s=="-" || s=="*" || s=="/" || s=="%")
            {
                if (stack.empty())
                    break;
                n1 = stack.back();
                stack.pop_back();
                if (stack.empty())
                    break;
                n2 = stack.back();
                stack.pop_back();
                if (s=="+")
                    ans = n1 + n2;
                else if (s=="-")
                    ans = n1 - n2;
                else if (s=="*")
                    ans = n1 * n2;
                else if (s=="/")
                    ans = n1 / n2;
                else if (s=="%")
                    ans = n1 % n2;
                stack.push_back(ans);
            }
            else if (s[0]<'0' || s[0]>'9')
                break;
            else
            {
                bool chk = true;
                for (int i=0;i<s.size();++i)
                {
                    if (s[i]<'0' || s[i]>'9')
                    {
                        chk = false;
                        break;
                    }
                }
                if (!chk)
                    break;
                stack.push_back(stoll(s));
            }
        }

        if (stack.size()!=1 || !prefix.empty())
            cout << "illegal" << endl;
        else
            cout << stack.front() << endl;
    }

    return 0;
}
