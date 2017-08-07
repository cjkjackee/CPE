#include <iostream>
#include <set>
using namespace std;

bool can_return;

int borrown(int cola, int emp, int n)
{
    int new_bottle=0;
    int tmp = cola+emp;

    if (tmp<3)
    {
        if (tmp>=n)
            can_return = true;
        else
            can_return = false;
        return cola;
    }

    if(tmp>=3)
    {
       new_bottle = tmp/3;
       tmp %= 3;
    }

//    cout << "new_bottle :" << new_bottle << endl;
//    cout << "empty :" << tmp << endl;
//    cout << "borrow" << n << endl;

    return cola+borrown(new_bottle,tmp,n);
}

int trade(int n, int emp)
{
    int new_bottle=0;
    int tmp = n+emp;

    if (tmp<3)
        return n;

    while(tmp>=3)
    {
        new_bottle = tmp/3;
        tmp %= 3;
    }

    if (tmp==2 || tmp+new_bottle==2)
    {
        ++new_bottle;
        tmp = 0;
    }

    if (new_bottle==2 && tmp==0)
        ++new_bottle;

    return n+trade(new_bottle,tmp);
}

int main ()
{
    int n;
    set<int> ans;
    int borrow0 = 0;
    int borrow1 = 0;
    int borrow2 = 0;

    while (cin >> n)
    {
        ans.clear();
        borrow0 = borrown(n,0,0);
//        cout << "borrow0 ans: " << borrow0 << endl;
//        cout << "return? :" << can_return << endl;
        if (can_return)
            ans.insert(borrow0);
        borrow1 = borrown(n,1,1);
//        cout << "borrow1 ans: " << borrow1 << endl;
//        cout << "return? :" <<  can_return << endl;
        if (can_return)
            ans.insert(borrow1);
        borrow2 = borrown(n,2,2);
//        cout << "borrow2 ans: " << borrow2 << endl;
//        cout << "return? :" <<  can_return << endl;
        if (can_return)
            ans.insert(borrow2);
        cout << *ans.rbegin() << endl;
    }

    return 0;
}
