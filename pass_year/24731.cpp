#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;

char s[30];
int ans;
vector<pair<int, int> > node[maxn]; /// first: ��node[i]����Ĵ�ׯ��  second: ����

int dfs(int to, int from)
{
	int lto, lans = 0, lmax = 0;
	for (int i = 0; i < node[to].size(); ++i)
	{
		lto = node[to][i].first;
		if (lto != from)
		{
			lans = dfs(lto, to) + node[to][i].second;///�ݹ����������������е��·
			ans = max(ans, lans + lmax);///��ǰ�õ��������·��ǰ��õ�����һ���������·֮��
			lmax = max(lmax, lans);
		}
	}
	return lmax;
}

int main()
{
	int u, v, l, i;
	bool ok = true;
	while (ok)
	{
		for (i = 0; i < maxn; ++i) node[i].clear();
		while (true)
		{
			if (gets(s) == 0)
			{
				ok = false;
				break;
			}
			if (s[0])
			{
				sscanf(s, "%d%d%d", &u, &v, &l);
				node[u].push_back(make_pair(v, l));
				node[v].push_back(make_pair(u, l));
			}
			else break;
		}
		ans = 0;
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}
