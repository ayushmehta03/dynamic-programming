#include<iostream>
#include<vector>
using namespace std;

int subCount(vector<int>&nums,int target,int n){
    vector<vector<int>>dp(n,vector<int>(target,0));


    for(int i=0;i<n;i++) dp[i][0]=1;
    if(nums[0]<=target) dp[0][nums[0]]=1;

    for(int ind=1;ind<n;ind++){
        for(int t=1;t<=target;t++){
            int nTake=dp[ind-1][t];
            int take=0;
            if(nums[ind]<=t){
                take=dp[ind-1][t-nums[ind]];

            }
            dp[ind][t]=nTake+take;
        }

    }
    return dp[n-1][target];
}

int main(){
    vector<int>arr={1,2,2,3};
    int target=3;
    int n=arr.size();
    int ans=subCount(arr,target,n);
    cout<<"The total no of subset with target sum is: "<<ans;

}