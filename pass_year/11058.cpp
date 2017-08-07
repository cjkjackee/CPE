#include<algorithm>
#include<cstdio>

using namespace std;

int N, M;
int main() {

    while(scanf("%d\n", &N) == 1) {
        int books[N];
        for(int i = 0; i < N; i++)
            scanf("%d", &books[i]);
        scanf("%d", &M);
        int min = 10000000, a, b;
        for(int i = 0; i < N; i++) {
            int c = books[i];
            int* ub = find(books, books + N, M - c);

            if(ub - books < N) {
                int j = ub - books;

                if(books[j] + books[i] == M && books[j] >= books[i] && i != j) {
                    if(books[j] - books[i] < min) {
                        a = books[i];
                        b = books[j];
                        min = b - a;
                    }
                }
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);

    }
    return 0;
}
