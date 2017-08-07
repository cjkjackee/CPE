#include <iostream>
#include <string>
#include <deque>
using namespace std;

int bottom;
deque<int> ver;
deque<int> hor;

void init_die ()
{
    ver.clear();
    hor.clear();
    ver.push_back(2);
    ver.push_back(1);
    ver.push_back(5);
    hor.push_back(3);
    hor.push_back(1);
    hor.push_back(4);
    bottom = 6;
    return ;
}

void mv_north()
{
    int tmp = bottom;
    bottom = ver[0];
    ver.pop_front();
    ver.push_back(tmp);
    hor[1] = ver[1];
    return;
}

void mv_south()
{
    int tmp = bottom;
    bottom = ver[2];
    ver.pop_back();
    ver.push_front(tmp);
    hor[1] = ver[1];
    return;
}

void mv_east()
{
    int tmp = bottom;
    bottom = hor[2];
    hor.pop_back();
    hor.push_front(tmp);
    ver[1] = hor[1];
    return ;
}

void mv_west()
{
    int tmp = bottom;
    bottom = hor[0];
    hor.pop_front();
    hor.push_back(tmp);
    ver[1] = hor[1];
    return ;
}

void die_state()
{
    cout << "ver state: " << ver[0] << ver[1] << ver[2] << endl;
    cout << "hor state: " << hor[0] << hor[1] << hor[2] << endl;
    cout << "bottom :" << bottom << endl;
    return;
}

int main ()
{
    int n;
    char c;
    string cmd;

    while (1)
    {
        init_die();
        cin >> n;

        if (!n)
            break;
        if (n>1024)
            break;

        for (int i=0;i<n;++i)
        {
            cin >> cmd;
            c = getchar();

            if (c==' ')
                continue;
            else
                cin.putback(c);

            if (cmd == "north")
                mv_north();
            else if (cmd == "south")
                mv_south();
            else if (cmd == "east")
                mv_east();
            else if (cmd == "west")
                mv_west();
            //die_state();
        }
        cout << hor[1] << endl;
        //die_state();
    }

    return 0;
}
