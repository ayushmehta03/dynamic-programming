#include<iostream>
#include<vector>

using namespace std;



int f(int i,int j,int n,vector<vector<int>>&triangle,vector<vector<int>>&dp){

    if(i==n-1) return triangle[n-1][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int dw=triangle[i][j]+f(i+1,j,n,triangle,dp);
    int dg=triangle[i][j]+f(i+1,j+1,n,triangle,dp);
    return dp[i][j]= min(dw,dg);
}
int main(){
    vector<vector<int>>triangle={
        {2},{3,4},{6,5,7},{4,1,8,3}

    };

    int n=triangle.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));

    int ans=f(0,0,n,triangle,dp);
    cout<<"The triangle min path sum is:"<<" "<<ans;

}