#include<iostream>
#include<vector>

using namespace std;

int trianglePathSum(int n,vector<vector<int>>&triangle){
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int j=0;j<n;j++){
        dp[n-1][j]=triangle[n-1][j];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int up=triangle[i][j]+dp[i+1][j];
            int dg=triangle[i][j]+dp[i+1][j+1];
            dp[i][j]=min(up,dg);
        }
    }
    return dp[0][0];
}


int main(){
    vector<vector<int>>triangle={
        {2},{3,4},{6,5,7},{4,1,8,3}

    };

    int n=triangle.size();

    int ans=trianglePathSum(n,triangle);
    cout<<"The triangle min path sum is:"<<" "<<ans;

}