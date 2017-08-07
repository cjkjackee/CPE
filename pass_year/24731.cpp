#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;

char s[30];
int ans;
vector<pair<int, int> > node[maxn]; /// first: 与node[i]连结的村庄号  second: 距离

int dfs(int to, int from)
{
	int lto, lans = 0, lmax = 0;
	for (int i = 0; i < node[to].size(); ++i)
	{
		lto = node[to][i].first;
		if (lto != from)
		{
			lans = dfs(lto, to) + node[to][i].second;///递归子树，返回子树中的最长路
			ans = max(ans, lans + lmax);///当前得到的子树最长路和前面得到的另一棵子树的最长路之和
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
