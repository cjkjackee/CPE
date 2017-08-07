#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main ()
{
	vector<string> store;
	int n;
	char c;
	string s;
	stringstream ss;

	while(c=getchar())
	{
		if(c=='0')
			break;

		if ((c>='a' && c<='z') || (c>='A' && c<='Z') )
		{
			cout << c;
			s.push_back(c);
		}
		else
		{
			if (!s.empty())
				store.push_back(s);
			s.clear();

			if (c>='0' && c<='9')
			{
				cin.putback(c);
				cin >> n;
				int i = store.size() - n;
				cout << store[i];
				store.push_back(store[i]);
				vector<string>::iterator it = store.begin();
				it += i;
				store.erase(it);
			}
			else
				cout << c;
		}
	}
	return 0;
}
