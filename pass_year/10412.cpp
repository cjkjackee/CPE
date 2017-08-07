#include <cstdio>
using namespace std;
int main()
{
  //  freopen("input.txt","rt",stdin);
    char keyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char line[1000];
    while (gets(line)){
        for (int i=0; line[i]; i++){
            if (line[i] == ' ') printf(" ");
            else{
                int j = 0;
                while (line[i] != keyboard[j+1]) j++;
                printf("%c",keyboard[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
