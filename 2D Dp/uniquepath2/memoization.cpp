#include<iostream>
#include<vector>
using namespace std;

int f(int i,int j,vector<vector<int>>&obst,vector<vector<int>>&dp){
   if(i>=0&&j>=0&&obst[i][j]==1) return 0;
    if(i==0&&j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int up=f(i-1,j,obst,dp);
    int left=f(i,j-1,obst,dp);
    return dp[i][j]=up+left;

}

int main(){
    vector<vector<int>>obstaclegrid={
        {0,0,0},{0,1,0},{0,0,0}
    };
    int m=obstaclegrid.size();
    int n=obstaclegrid[0].size();
    
        vector<vector<int>>dp(m,vector<int>(n,-1));


    
    int ans=f(m-1,n-1,obstaclegrid,dp);
    cout<<"the ways through which we can reach the end without any obstacles: "<<" "<<ans;
    

}

