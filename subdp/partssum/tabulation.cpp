#include<iostream>
#include<vector>
using namespace std;



bool canPartiation(vector<int>&nums,int n){
    int totalSum=0;
    for(int i=0;i<n;i++){
    totalSum+=nums[i];
    }

    if(totalSum%2!=0) return false;
    int target=totalSum/2;
    vector<vector<bool>>dp(n,vector<bool>(target+1,false));



    for(int i=0;i<n;i++) dp[i][0]=true;
    if(nums[0]<=target) dp[0][nums[0]]=true;

    for(int i=1;i<n;i++){
        for(int t=1;t<=target;t++){
            bool nTake=dp[i-1][t];
            bool take=false;
            if(nums[i]<=t){
                take=dp[i-1][t-nums[i]];
            }
            dp[i][t]=take||nTake;
        }
    }
    return dp[n-1][target];

}


int main(){
    vector<int>nums={1,5,11,5};
    int n=nums.size();
    if(canPartiation(nums,n)){
        cout<<"partition sum possible";
    }
    else{
        cout<<"Not possible";
    }
    return 0;
}


