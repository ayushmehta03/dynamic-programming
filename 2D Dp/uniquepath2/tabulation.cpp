#include<iostream>
#include<vector>
using namespace std;

int unqiuePaths2(int m,int n,vector<vector<int>>&obst ){
    int dp[m][n];

    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
     if(i>=0&&j>=0&&obst[i][j]==1) dp[i][j]=0;
     else if(i==0 &&j==0) dp[i][j]=1;
     else{
        int up=0;
        int left=0;

        if(i>0) up=dp[i-1][j];
        if(j>0) left=dp[i][j-1];
        dp[i][j]=up+left;

     }
    }
    }
        return dp[m-1][n-1];


}

int main(){
    vector<vector<int>>obstaclegrid={
        {0,0,0},{0,1,0},{0,0,0}
    };
    int m=obstaclegrid.size();
    int n=obstaclegrid[0].size();
    

        int ans=unqiuePaths2(m,n,obstaclegrid);


    
    cout<<"the ways through which we can reach the end without any obstacles: "<<" "<<ans;
    

}

