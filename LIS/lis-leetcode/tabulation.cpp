#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lis(vector<int>&nums){
        int n=nums.size();
     vector<vector<int>>dp(n+1,vector<int>(n+1,0));

     for(int idx=n-1;idx>=0;idx--){
        for(int previdx=idx-1;previdx>=-1;previdx--){
            int len=0+dp[idx+1][previdx+1];

            if(previdx==-1 || nums[idx]>nums[previdx]){
                len=max(len,1+dp[idx+1][idx+1]);
            }

            dp[idx][previdx+1]=len;
        }
     }

     return dp[0][-1+1];

}

int main(){
    vector<int>nums={10,9,2,5,3,7,101,18};



    int ans=lis(nums);


    cout<<"the longest increasing subsequence will be:"<<" "<<ans;

}