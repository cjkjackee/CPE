#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    int n;
    while (cin >> n && n)
    {
        int top = 1;
        int north = 2;
        int west = 3;
        int east = 4;
        int south = 5;
        int bottom = 6;

        while (n--)
        {
            string temp;
            cin >> temp;

            if (temp == "north")
            {
                int backup = top;
                top = south;
                south = bottom;
                bottom = north;
                north = backup;
            }
            else if (temp == "south")
            {
                int backup = top;
                top = north;
                north = bottom;
                bottom = south;
                south = backup;
            }
            else if (temp == "east")
            {
                int backup = top;
                top = west;
                west = bottom;
                bottom = east;
                east = backup;
            }
            else if (temp == "west")
            {
                int backup = top;
                top = east;
                east = bottom;
                bottom = west;
                west = backup;
            }
        }
        cout << top << endl;
    }
    return 0;
}
