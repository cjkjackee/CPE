#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class bignum
{
public:
	bignum(){};
	~bignum(){};
	bignum(long long n)
	{
		this->num.push_back(n);
	}
	void operator= (int n)
	{
		this->num.clear();
		this->num.push_back(n);
	}
	void operator= (bignum num2)
	{
		this->num.clear();
		this->num = num2.num;
	}
	bignum operator+ (int n)
	{
		bignum ans;
		ans = this->num[0] + n;
		while(ans.num[0]>1000000000000000000)
		{
			ans.num[1] += ans.num[0]/1000000000000000000;
			ans.num[0] %= 1000000000000000000;
		}
		return ans;
	}
	bignum operator+ (bignum num2)
	{
		bignum ans;
		bignum operand;
		int s;
		if (num2.num.size()>this->num.size())
		{
			s = this->num.size();
			ans = num2;
			operand = *this;
		}
		else
		{
			s = num2.num.size();
			ans = *this;
			operand = num2;
		}

		for (int i=0;i<s;++i)
			ans.num[i] = ans.num[i] + operand.num[i];

		for (int i=0;i<s;++i)
		{
			if (ans.num[i]>1000000000000000000)
			{
				if (i+1>=ans.num.size())
					ans.num.push_back(0);
				ans.num[i+1] += ans.num[i]/ 1000000000000000000;
				ans.num[i] %= 1000000000000000000;
			}
		}

		return ans;
	}
	friend ostream& operator<< (ostream& os, const bignum& n);

private:
	vector<long long> num;
};

ostream& operator<< (ostream& os, const bignum& n)
{
	os << n.num[n.num.size()-1];
	for (int i=n.num.size()-2;i>=0;--i)
		os << setfill('0') << setw(18) << n.num[i];
	return os;
}

int main ()
{
	int n;

	while (cin >> n)
	{
		bignum n1 = 1;
		bignum n2 = 1;
		bignum ans = n2;
		bignum stk = n1;
		if (n==1)
			cout << 1 << endl;
		else if (n == 2)
			cout << 1  << endl;
		else
		{
			for (int i=n-2;i>0;--i)
			{
				bignum tmp = ans;
				ans = ans + stk;
				stk = tmp;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
