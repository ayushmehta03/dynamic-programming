#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int f(int idx,int previdx,int n, vector<int>&nums,    vector<vector<int>>&dp){
    if(idx==n) return 0;
    if(dp[idx][previdx+1]!=-1) return dp[idx][previdx+1];

    int len=0+f(idx+1,previdx,n,nums,dp);

    if(previdx==-1 || nums[idx]>nums[previdx]){
        len=max(len,1+f(idx+1,idx,n,nums,dp));
    }

    return dp[idx][previdx+1]= len;

}

int main(){
    vector<int>nums={10,9,2,5,3,7,101,18};

    int n=nums.size();

    vector<vector<int>>dp(n,vector<int>(n+1,-1));

    int ans=f(0,-1,n,nums,dp);


    cout<<"the longest increasing subsequence will be:"<<" "<<ans;

}