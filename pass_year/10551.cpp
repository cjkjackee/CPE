#include<stdio.h>
   #include<stdlib.h>
   #include<math.h>
  #include<iostream>
  #include <iomanip>
  using namespace std;
int main()
{
        int n,counter,left,i=0,x=0,y=0;
      while(cin>>n){
        for(counter=1;counter<n;counter+=6*i){
                i++;
        }
        x=i;
        left=n-counter;
        for(;left<0&&x!=-y;){
                y--;
                left++;
        }
        for(;left<0&&x>0;){
                x--;
                left++;
        }
        for(;left<0&&y<0;){
                x--;
                y++;
                left++;
        }
        for(;left<0&&x!=-y;){
                y++;
                left++;
        }
        for(;left<0&&x<0;){
                x++;
                left++;
        }
        for(;left<0&&y>0;){
                x++;
                y--;
                left++;
        }
        cout<<x<<" "<<y<<'\n';
        x=0;
        y=0;
        counter=1;
        i=0;
      }
}
