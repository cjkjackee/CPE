#include <stdio.h>
#include <map>
#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;
int main() {
    int n, cases = 0;
    int i, m;
    string line;
    while(scanf("%d", &n) == 1) {
        if(cases)   puts("");
        cases++;
        map<string, int> R;
        while(getline(cin, line)) {
            if(line == "EndOfText") break;
            m = line.length();
            for(i = 0; i < m; i++) {
                if(line[i] >= 'a' && line[i] <= 'z'){}
                else if(line[i] >= 'A' && line[i] <= 'Z')
                    line[i] = line[i]+32;
                else
                    line[i] = ' ';
            }
            stringstream sin(line);
            while(sin >> line)
                R[line]++;
        }
        int found = 0;
        for(map<string, int>::iterator it = R.begin();
            it != R.end(); it++) {
            if(it->second == n) {
                cout << it->first << endl;
                found = 1;
            }
        }
        if(!found)
            puts("There is no such word.");
    }
    return 0;
}
