#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char map[1000][1000] = {0};
bool visited[1000][1000] = {0};

void DFS( int, int );

int main(){
  int n, H, W, maxarea,j,k;
  while(cin>>n){
    for( int i = 1 ; i <= n ; i++ ){
      cin>>H>>W;
      getchar();
      memset( visited, 0, sizeof(visited) );
      int letters[30] = {0};
      maxarea = 0;
      for(j = 1 ; j <= H ; j++ ){
        for(k = 1 ; k <= W ; k++ ){
            cin>>map[j][k];
        }
        getchar();
      }
      for(j = 1 ; j <= H ; j++ )
        for(k = 1 ; k <= W ; k++ ){
          if( !visited[j][k] ){
            maxarea = max( ++letters[map[j][k]-'a'], maxarea );
            DFS( j, k );
          }
        }
      cout<<"World #"<<i<<endl;
      for(j = maxarea ; j >= 1 ; j-- ){
        for(k = 0 ; k < 26 ; k++ ){
            if( letters[k] == j ){
               printf( "%c: %d\n", 'a'+k, j );
            }
        }
      }



    }
  }
  return 0;
}

void DFS( int x, int y ){
  visited[x][y] = 1;
  if( map[x+1][y] == map[x][y] && !visited[x+1][y] ) DFS(x+1,y);
  if( map[x-1][y] == map[x][y] && !visited[x-1][y] ) DFS(x-1,y);
  if( map[x][y+1] == map[x][y] && !visited[x][y+1] ) DFS(x,y+1);
  if( map[x][y-1] == map[x][y] && !visited[x][y-1] ) DFS(x,y-1);
}
