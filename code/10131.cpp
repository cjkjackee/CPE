#include <iostream>
#include <set>
using namespace std;

int main ()
{
	multiset<int> book;
	int n;

	while(cin >> n)
	{
		book.clear();

		int value;
		int money;
		multiset<int>::iterator it;
		multiset<int>::iterator it2;

		for (int i=0;i<n;++i)
		{
			cin >> value;
			book.insert(value);
		}
		cin >> money;

		value = money/2;

		it = book.lower_bound(value);
		while(1)
		{
			for (it2 = book.begin();it2!=book.end();++it2)
			{
				if (it2==it)
					continue;
				if (*it+*it2==money)
					break;
			}

			if (*it+*it2==money)
			{
				if (*it>*it2)
				{
					multiset<int>::iterator tmp = it;
					it = it2;
					it2 = tmp;
				}
				break;
			}
			else
				--it;
		}

		cout << "Peter should buy books whose prices are " << *it << " and " << *(it2) << '.' << endl;
		cout << endl;
	}

	return 0;
}
