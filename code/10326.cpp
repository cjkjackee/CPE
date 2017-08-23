#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

class coordinate
{
public:
    coordinate(){};
    ~coordinate(){};
    coordinate(int l, int r, int c)
    {
        L = l;
        R = r;
        C = c;
    }
    void clear()
    {
        L = 0;
        R = 0;
        C = 0;
        Step = 0;
    }
    int l()
    {
        return L;
    }
    void l(int n)
    {
        L = n;
        return ;
    }
    int r()
    {
        return R;
    }
    void r (int n)
    {
        R = n;
        return ;
    }
    int c()
    {
        return C;
    }
    void c(int n)
    {
        C = n;
        return ;
    }
    int step ()
    {
        return Step;
    }
    void step (int n)
    {
        Step = n;
        return;
    }
    coordinate operator= (coordinate c2)
    {
        this->L = c2.l();
        this->R = c2.r();
        this->C = c2.c();
        this->Step = c2.step();
        return c2;
    }
    bool operator== (coordinate c2)
    {
        if (this->L == c2.l() && this->R == c2.r() && this->C == c2.c())
            return true;
        else
            return false;
    }
    bool operator!= (coordinate c2)
    {
        if (*this==c2)
            return false;
        else
            return true;
    }
private:
    int L;
    int R;
    int C;
    int Step;
};

istream& operator>> (istream& is, coordinate& i)
{
    int l,r,c;
    is >> l >> r >> c;
    i.l(l);
    i.r(r);
    i.c(c);
    return is;
}

set<int> ans;
queue<coordinate> path;
vector<char> map[30][30];
coordinate init;
coordinate start;
coordinate last;
coordinate previous;

void find();
void up(coordinate);
void down(coordinate);
void search(coordinate);

int main ()
{
    char c;
    coordinate zero;
    zero.clear();

    while (1)
    {
        init.clear();
        start.clear();
        last.clear();
        ans.clear();
        cin >> init;

        if (init==zero)
            break;

        for (int i=0;i<init.l();++i)
        {
            for (int x=0;x<init.r();++x)
            {
                map[i][x].clear();
                for (int z=0;z<init.c();++z)
                {
                    cin >> c;
                    if (c == 'S')
                    {
                        start.l(i);
                        start.r(x);
                        start.c(z);
                        path.push(start);
                    }
                    else if (c == 'E')
                    {
                        last.l(i);
                        last.r(x);
                        last.c(z);
                        c = '.';
                    }
                    map[i][x].push_back(c);
                }
            }
        }

        find();
//        cout << ans.size() << endl;
        if (ans.size())
            cout << "Escaped in " <<  *ans.begin() << " minute(s)." << endl;
        else
            cout << "Trapped!" << endl;
    }

    return 0;
}


void find ()
{
    coordinate now;
    while(1)
    {
        if (!path.size())
            break;
        now = path.front();
        path.pop();
        if (now==last)
        {
            ans.insert(now.step());
            continue;
        }
        up(now);
        down(now);
        search(now);
    }

    return ;
}

void up (coordinate now)
{
    coordinate next;
    next.step(now.step()+1);
    if (now.l() && map[now.l()-1][now.r()][now.c()]=='.')
    {
        next.l(now.l()-1);
        next.r(now.r());
        next.c(now.c());
        path.push(next);
        map[now.l()-1][now.r()][now.c()] = 'x';
    }
    return ;
}

void down (coordinate now)
{
    coordinate next;
    next.step(now.step()+1);
    if (now.l()+1<init.l() && map[now.l()+1][now.r()][now.c()]=='.')
    {
        next.l(now.l()+1);
        next.r(now.r());
        next.c(now.c());
        path.push(next);
        map[now.l()+1][now.r()][now.c()] = 'x';
    }
    return;
}

void search(coordinate now)
{
    coordinate next;

    next.step(now.step() + 1);
    if (now.r() && map[now.l()][now.r()-1][now.c()]=='.')
    {
        next.l(now.l());
        next.r(now.r()-1);
        next.c(now.c());
        path.push(next);
        map[now.l()][now.r()-1][now.c()] = 'x';
    }
    if (now.r()+1<init.r() && map[now.l()][now.r()+1][now.c()]=='.')
    {
        next.l(now.l());
        next.r(now.r()+1);
        next.c(now.c());
        path.push(next);
        map[now.l()][now.r()+1][now.c()] = 'x';
    }
    if (now.c() && map[now.l()][now.r()][now.c()-1]=='.')
    {
        next.l(now.l());
        next.r(now.r());
        next.c(now.c()-1);
        path.push(next);
        map[now.l()][now.r()][now.c()-1] = 'x';
    }
    if (now.c()+1<init.c() && map[now.l()][now.r()][now.c()+1]=='.')
    {
        next.l(now.l());
        next.r(now.r());
        next.c(now.c()+1);
        path.push(next);
        map[now.l()][now.r()][now.c()+1] = 'x';
    }

    return;
}
