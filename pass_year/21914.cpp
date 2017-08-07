#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char sentence[101][101];
    int N=0,length[101];
    int Max_length=0;
    while (gets(sentence[N])) {
        length[N] = strlen(sentence[N]);
        if (length[N] > Max_length) Max_length = length[N];
        N++;
    }
    for (int i=0; i<Max_length; i++){
        for (int j=N-1; j>=0; j--){
            if (i < length[j])
                printf("%c",sentence[j][i]);
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
