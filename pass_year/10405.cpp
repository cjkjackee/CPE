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
            // 讀進 input 然後相減取絕對值
            if (i!=0)
                record.push_back(abs(last - k));
        }
        sort (record.begin(), record.end());
        // sort 之，如果 1~(n-1) 的值都存在則表示這是一個 Jolly jumper
        for (int i=0; i!=n-1; i++){
            if (record.at(i) != (i+1)){
                isjolly = false;
                break;
            }
        }
        // 注意 output 大小寫
        if (isjolly)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }
    return 0;
}
