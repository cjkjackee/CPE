#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

map<string,int> dir;

bool disk_tree(string head, string path, int order)
{
	bool r_value = false;
	bool check = false;
	string name;
	string next_path;
	stringstream ss;
	map<string,int>::iterator it;

	ss << path;
	ss >> name;
	getline(ss,next_path);

	if (name.empty())
		return 0;

	it = dir.find(name);
	if (it!=dir.end())
	{
		r_value = true;
		order = dir[name];
		++order;
	}
	else
	{
		it = dir.find(head);
		if (it!=dir.end())
			dir.insert(++it,pair<string,int>(name,order));
		else
			dir[name] = order;
		++order;
	}

	check = disk_tree(name, next_path, order);

	if (check)
	{
		string under;
		stringstream ss;
		ss << next_path;
		ss >> under;
		it = dir.find(name);
		dir.erase(it);
		it = dir.find(under);
		order = dir[under];
		dir.insert(it,pair<string,int>(name,--order));
	}

	return r_value;
}

void list ()
{
	for (map<string,int>::iterator it=dir.begin();it!=dir.end();++it)
	{
		for (int i=0;i<it->second;++i)
			cout << ' ';
		cout << it->first << endl;
	}

	return ;
}

int main ()
{
	int n;
	string s;

	cin >> n;
	for (int z=0;z<n;++z)
	{
		stringstream ss;
		cin >> s;
		for (int i=0;i<s.size();++i)
		{
			if (s[i]==92)
				s[i] = ' ';
		}
		s.push_back(' ');

		disk_tree("",s,0);
	}

	list();

	return 0;
}
