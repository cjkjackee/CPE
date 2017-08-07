#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    while(cin>>n && !cin.eof()){
        vector<int> record;
        int k, last;
        bool isjolly = true;
        for (int i=0; i!=n; i++){
            if(i!=0)
                last = k;
            cin >> k;
            // �x�M input Ȼ�����pȡ�^��ֵ
            if (i!=0)
                record.push_back(abs(last - k));
        }
        sort (record.begin(), record.end());
        // sort ֮����� 1~(n-1) ��ֵ�����ڄt��ʾ�@��һ�� Jolly jumper
        for (int i=0; i!=n-1; i++){
            if (record.at(i) != (i+1)){
                isjolly = false;
                break;
            }
        }
        // ע�� output ��С��
        if (isjolly)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }
    return 0;
}
