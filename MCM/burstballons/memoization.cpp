#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int maxi=INT_MIN;
    for(int idx=i;idx<=j;idx++){
        int cost=nums[i-1]*nums[idx]*nums[j+1]+f(i,idx-1,nums,dp)+f(idx+1,j,nums,dp);
        maxi=max(maxi,cost);
    }
    return dp[i][j]= maxi;
}


int maxCoins(vector<int>&nums){
    int n=nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(),1);
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return f(1,n,nums,dp);


}

int main(){
    vector<int>nums={3,1,5,8};
    int ans=maxCoins(nums);
    cout<<"The maximu coins we can earn is: "<<ans;
    return 0;

}