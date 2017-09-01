#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main ()
{
    int T , n;
    int ans;
    string s;
    vector<int> cmd;

    cin >> T;
    for (int t=0;t<T;++t)
    {
        cmd.clear();
        ans = 0;
        cin >> n;
        for (int N=0;N<n;++N)
        {
            cin >> s;
            if (s=="LEFT")
            {
                ans -= 1;
                cmd.push_back(-1);
            }
            else if (s=="RIGHT")
            {
                ans += 1;
                cmd.push_back(1);
            }
            else if (s=="SAME")
            {
                int x;
                cin >> s;
                cin >> x;
                ans += cmd[x-1];
                cmd.push_back(cmd[x-1]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
