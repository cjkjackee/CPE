#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

bool isprime (int n)
{
	if (n%2==0 && n!=2)
		return false;
	if (n%3==0 && n!=3)
		return false;
	for (int i=5;i*i<=n;i+=2)
	{
		if (n%i==0)
			return false;
	}
	return true;
}

int main ()
{
	vector<int> person;
	vector<int>::iterator now;
	vector<int>::iterator it;
    int n;
    int p;

    while (1)
    {
        cin >> n;
		person.clear();
        p = 2;

        if (!n)
            break;

		person.assign(n,1);

		now = person.begin();
		while (person.size()!=1)
		{
			if (isprime(p))
			{
				int x;
				for (x=p-1;x!=0;--x)
				{
					++now;
					if (now!=person.begin() && *now==1)
					{
						it = now-1;
						*now += *it;
					}
					if (now==person.end())
					{
						now = person.begin();
						x -= 1;
						break;
					}
				}
				if (now == person.begin() && x>person.size())
				{
					x %= person.size();
				}
				for (;x!=0;--x)
				{
					++now;
					if (now==person.end())
						now = person.begin();
				}
				it = now + 1;
				if (it!=person.end() && *it==1)
					*it += *now;
				now = person.erase(now);
				if (now==person.end())
					now = person.begin();
			}
			++p;
		}
		cout << person[0] << endl;
    }

    return 0;
}
