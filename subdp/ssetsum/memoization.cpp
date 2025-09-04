#include<iostream>
#include<vector>
using namespace std;

int f(int index,int target,vector<int>&nums,vector<vector<int>>&dp){
    if(target==0) return true;
    if(index==0) return nums[0]==target;
    if(dp[index][target]!=-1) return dp[index][target];
    bool nTake=f(index-1,target,nums,dp);
    bool take=false;
    if(target>=nums[index]){
        take=f(index-1,target-nums[index],nums,dp);
    }
    return dp[index][target]= take||nTake;
}

int main(){
    vector<int>nums={2,3,1,1};

    int t=4;
        int n=nums.size();

    vector<vector<int>>dp(n+1,vector<int>(t+1,-1));
    if(f(n-1,t,nums,dp)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;

}