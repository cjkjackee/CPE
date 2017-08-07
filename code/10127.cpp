#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> dataX, dataY, dataR;
vector<int> ableX, ableY, ableR;

int test(int num)
{
    int x = dataX[num];
    int y = dataY[num];
    int r = dataR[num];
    int dx, dy;
    int dist;
    int area = r * r;
    bool able = true;

    ableX.clear();
    ableY.clear();
    ableR.clear();
    ableX.push_back(x);
    ableY.push_back(y);
    ableR.push_back(r);

    for (int i=0;i<dataX.size();++i)
    {
        if (i==num)
            continue;

        dx = x - dataX[i];
        dy = y - dataY[i];
        dist = pow(dx,2) + pow(dy,2);

        //cout << sqrt(dist) << endl;
        //cout << (r+dataR[i]) << endl;

        if (sqrt(dist) > (r+dataR[i]) )
        {
            for (int z=0;z<ableY.size();++z)
            {
                dx = dataX[i] - ableX[z];
                dy = dataY[i] - ableY[z];
                dist = pow(dx,2) + pow(dy,2);

                if (sqrt(dist) < (dataR[i]+ableR[z]) )
                {
                    able = false;
                    break;
                }
            }

            if (able)
            {
                area += dataR[i] * dataR[i];
                ableX.push_back(dataX[i]);
                ableY.push_back(dataY[i]);
                ableR.push_back(dataR[i]);
            }
            able = true;
        }
    }

    return area;
}

int main ()
{
    int n;
    int c;
    int x, y, r;
    int area;
    int max;

    cin >> n;
    for (int z=0;z<n;++z)
    {
        //init
        dataX.clear();
        dataY.clear();
        dataR.clear();
        max = 0;

        cin >> c;
        for (int i=0;i<c;++i)
        {
            cin >> x;
            cin >> y;
            cin >> r;

            dataX.push_back(x);
            dataY.push_back(y);
            dataR.push_back(r);
        }

        for (int i=0;i<c;++i)
        {
            area = test(i);
            if (area > max)
                max = area;
        }

        cout << max << endl;
    }

    return 0;
}
