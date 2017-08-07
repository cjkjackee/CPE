#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int n;
  while( scanf( "%d", &n ) != EOF && n ){
    while( n/10 ) n = n/10 + n%10;
    printf( "%d\n", n );
  }
  return 0;
}
