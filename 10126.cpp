#include <iostream>
#include <string>
#include <set>
#include <stdio.h>
#include <sstream>
using namespace std;

int main ()
{
    unsigned int n;
    string str;
    set<string> word;
    multiset<string> times;
    bool flag = false;
    char c;
    stringstream tmp;

    while (cin >> n)
    {
        //init
        times.clear();
        word.clear();

        while (cin >> str)
        {
            tmp.clear();
            tmp << str;
            if (str=="EndOfText")
                break;
            for (unsigned int i=0;i<str.size();++i)
            {
                tmp >> c;
                if ((c<'a' || c>'z'))
                {
                    if ((c>='A' && c<='Z'))
                    {
                        c += 32;
                    }
                    else
                    {
                        c = ' ';
                    }
                }
                tmp << c;
            }

            while (tmp >> str)
            {
                word.insert(str);
                times.insert(str);
            }
        }

        for (set<string>::iterator it=word.begin();it!=word.end();++it)
        {
            if (times.count(*it) == n)
            {
                cout << *it << endl;
                flag = true;
            }
        }

        if (!flag)
            cout << "There is no such word." << endl;

        cout << endl;
    }

    return 0;
}
