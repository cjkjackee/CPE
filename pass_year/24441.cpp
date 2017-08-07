#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int T;
  string month;
  int day, year;
  int t1, t2;
  while( scanf( "%d", &T ) != EOF ){
    for( int i = 1 ; i <= T ; i++ ){
      cin >> month;
      scanf( "%d, %d", &day, &year );
      if( (month[0] == 'J' && month[1] == 'a') || month[0] == 'F' ) year--;
      t1 = year/4 - year/100 + year/400;
      cin >> month;
      scanf( "%d, %d", &day, &year );
      if( (month[0] == 'J' && month[1] == 'a') || month[0] == 'F' ) year--;
      if( month[0] == 'F' && day == 29 ) year++;
      t2 = year/4 - year/100 + year/400;

      printf( "Case %d: %d\n", i, t2-t1 );
    }
  }
  return 0;
}
