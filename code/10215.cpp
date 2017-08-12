#include <iostream>
#include <vector>
using namespace std;

#define max 500

vector<char> map[max];

int main ()
{
	int no, size;

	cin >> no;
	for (int z=0;z<no;++z)
	{
		cin >> size;
		for (int i=0;i<size;++i)
		{
			map[i].clear();
			map[i].assign(size,'0');
		}

		for (int x=0;x<size;++x)
		{
			for (int i=0;i<size;++i)
			{
				char c;
				cin >> c;

				if (c=='*')
				{
					map[x][i] = c;
					if (x-1>=0)
					{
						map[x-1][i] += 1;
						if (i-1>=0)
							map[x-1][i-1] += 1;
						if (i+1<size)
							map[x-1][i+1] += 1;
					}
					if (i-1>=0)
						map[x][i-1] += 1;
					if (i+1<size)
						map[x][i+1] += 1;
					if (x+1<size)
					{
						map[x+1][i] += 1;
						if (i-1>=0)
							map[x+1][i-1] += 1;
						if (i+1<size)
							map[x+1][i+1] += 1;
					}
				}
			}
		}

		for (int x=0;x<size;++x)
		{
			for (int i=0;i<size;++i)
			{
				char c;
				cin >> c;
				if (c == 'x')
				 	cout << map[x][i];
				else
					cout << c;
			}
			cout << endl;
		}
	}
	return 0;
}
