#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	int n, r, c;
	int in;
	vector<int> map[100];

	cin >> n;
	for (int z=0;z<n;++z)
	{
		cin >> r;
		cin >> c;

		for (int i=0;i<r;++i)
		{
			map[i].clear();
			for (int x=0;x<c;++x)
			{
				cin >> in;
				if (!i && x)
					in += map[i][x-1];
				else if (i)
				{
					if (!x)
						in += map[i-1][x];
					else
					{
						if (map[i-1][x] > map[i][x-1])
							in += map[i][x-1];
						else
							in += map[i-1][x];
					}
				}
				map[i].push_back(in);
			}
		}

		cout << map[r-1][c-1] << endl;
	}

	return 0;
}
