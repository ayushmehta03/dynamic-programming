#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lis(vector<int>&nums){
        int n=nums.size();
        int maxi=1;
        vector<int>dp(n,1);
        for(int idx=0;idx<n;idx++){
        for(int prev=0;prev<idx;prev++){
         if(nums[idx]>nums[prev]){
            dp[idx]=max(dp[idx],dp[prev]+1);
         }

        }
        maxi=max(maxi,dp[idx]);
        }
        return maxi;

}

int main(){
    vector<int>nums={10,9,2,5,3,7,101,18};



    int ans=lis(nums);


    cout<<"the longest increasing subsequence will be:"<<" "<<ans;

}