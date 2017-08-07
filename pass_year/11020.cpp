#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char Table[][11]={
        "0111001111",
        "0111001110",
        "0111001100",
        "0111001000",
        "0111000000",
        "0110000000",
        "0100000000",
        "0010000000",
        "1111001110",
        "1111001100",
        "1111001000",
        "1111000000",
        "1110000000",
        "1100000000"
    };
    int T, hash[255];
    char str[201];
    hash['c'] = 0, hash['d'] = 1, hash['e'] = 2,
    hash['f'] = 3, hash['g'] = 4, hash['a'] = 5,
    hash['b'] = 6, hash['C'] = 7, hash['D'] = 8,
    hash['E'] = 9, hash['F'] = 10, hash['G'] = 11,
    hash['A'] = 12, hash['B'] = 13;
    scanf("%d", &T);
    gets(str);
    while(T--){
        int state[10]={}, Ans[10]={};
        gets(str);
        for(int i = 0; str[i]; i++){
            int t = hash[str[i]];
            for(int j = 0; j < 10; j++){
                if(Table[t][j] == '1' && !state[j])  Ans[j]++, state[j] = 1;
                if(Table[t][j] == '0')    state[j] = 0;
            }
        }
        printf("%d", Ans[0]);
        for(int i = 1; i < 10; i++)
            printf(" %d", Ans[i]);
        puts("");
    }
    return 0;
}
