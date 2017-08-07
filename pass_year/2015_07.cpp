#include<iostream>
#include<vector>
#include<stdio.h>
#include <climits>
using namespace std;

int minPathSum(vector<vector<int> > &grid) {
        int row = grid.size(),col;
        if(row == 0)return 0;
        else col = grid[0].size();
        vector<vector<int> >dp(row+1, vector<int>(col+1, INT_MAX));
        dp[0][1] = 0;
        for(int i = 1; i <= row; i++)
            for(int j = 1; j <= col; j++)
                dp[i][j] = grid[i-1][j-1] + min(dp[i][j-1], dp[i-1][j]);
        return dp[row][col];
    }
int main()
{
    int n,row,col,a,b;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>row>>col;
        vector<vector<int> >grid(row, vector<int>(col));
        for(a = 0; a < row; a++){
            for(b = 0; b < col; b++){
                cin>>grid[a][b];
            }
        }
        cout<<minPathSum(grid)<<endl;
    }
    return 0;
}
