#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int main(){
    int n;
    queue<int> cards;
    bool comma;
    while( scanf( "%d", &n ) != EOF && n != 0 ){
        for( int i = 1 ; i <= n ; i++ ){
            cards.push(i);
        }
        printf( "Discarded cards:" );
        comma = false;
        while( cards.size() != 1 ){
            if( comma ){
                printf( "," );
            }
            comma = true;
            printf( " " );
            printf( "%d", cards.front() );
            cards.pop();
            cards.push(cards.front());
            cards.pop();
        }
        printf( "\n" );
        printf( "Remaining card: %d\n", cards.front() );
        cards.pop();
    }
    return 0;
}
