#include<iostream>
#include<vector>
using namespace std;


int f(int i,int j,vector<vector<int>>&dp){
   
    if(i==0 &&j==0) return 1;
    if(i<0 ||j<0) return 0;
       if(dp[i][j]!=-1) return dp[i][j];


    int up=f(i-1,j,dp);
    int left=f(i,j-1,dp);
    return dp[i][j]=up+left;


}


int main(){
    int m=3;
    int n=7;
    vector<vector<int>>dp(m,vector<int>(n,-1));
    int ans=f(m-1,n-1,dp);
    cout<<" "<<ans;
}