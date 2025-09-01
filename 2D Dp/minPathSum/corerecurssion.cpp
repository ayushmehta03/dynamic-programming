#include<iostream>
#include<vector>
using namespace std;

int f(int i,int j,vector<vector<int>>&grid){
    if(i==0&&j==0) return grid[i][j];
    if(i<0||j<0) return 1e9;
    int up=grid[i][j]+f(i-1,j,grid);
    int left=grid[i][j]+f(i,j-1,grid);
    return min(up,left);
}

int main(){
    vector<vector<int>>grid={
        {1,3,1},{1,5,1},{4,2,1}
    };

    int n=grid.size();
    int m=grid[0].size();

    int ans=f(n-1,m-1,grid);
    cout<<"The min cost to reach the destination is:"<<" "<<ans;
    return 0;

}