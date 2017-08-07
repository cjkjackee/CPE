#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, i;
	double mini, tmp, a[10], r[10];

	scanf("%d", &n);

	while (n--)
	{
		scanf("%d", &m);

		for (i = 0; i < m; scanf("%lf", &a[i++]));

		sort(a, a + m);
		mini = 1e100;

		do
		{
			memcpy(r, a, sizeof(a));

			for (i = 1; i < m; i++)
				for (int j = 0; j < i; j++)
				{
					tmp = sqrt((a[j] + a[i]) * (a[j] + a[i]) - (a[j] - a[i]) * (a[j] - a[i])) + r[j];
					r[i] = max(r[i], tmp);
				}

			tmp = 0.0;

			for (i = 0; i < m; tmp = max(r[i] + a[i++], tmp));

			mini = min(mini, tmp);
		} while (next_permutation(a, a + m));

		printf("%.3f\n", mini);
	}

	return 0;
}
