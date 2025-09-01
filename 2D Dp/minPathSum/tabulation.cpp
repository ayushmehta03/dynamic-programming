#include<iostream>
#include<vector>
using namespace std;


int pathMinSum(int n,int m,vector<vector<int>>&grid){
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0&&j==0) dp[i][j]=grid[i][j];
          else{
            int up=grid[i][j];
            if(i>0) up+=dp[i-1][j];
            else up+=1e9;
            int left=grid[i][j];
            if(j>0) left+=dp[i][j-1];
            else left+=1e9;

            dp[i][j]=min(up,left);
            
        }
        
    }
}
    return dp[n-1][m-1];


}
int main(){
        vector<vector<int>>grid={
        {1,3,1},{1,5,1},{4,2,1}
    };

    int n=grid.size();
    int m=grid[0].size();

    int ans=pathMinSum(n,m,grid);
    cout<<"The minimu cost to reach destination is"<<" "<<ans;
}