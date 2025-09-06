#include<iostream>
#include<vector>
using namespace std;

int f(vector<int>&nums,int idx,int target,vector<vector<int>>&dp){
    if(target==0) return 1;
    if(idx==0){
        return nums[0]==target;
    }

    int nPick=f(nums,idx-1,target,dp);
    int pick=0;
    if(nums[idx]<=target){
        pick=f(nums,idx-1,target-nums[idx],dp);
    }

    return dp[idx][target]= pick+nPick;
}


int cntSub(vector<int>&arr,int t, int n){
    vector<vector<int>>dp(n,vector<int>(t+1,-1));
    return f(arr,n-1,t,dp);
}


int main(){

    vector<int>arr={1,2,2,3};
    int target=3;
    int n=arr.size();
    int ans=cntSub(arr,target,n);
    cout<<"The total no of subset with target sum is: "<<ans;


}