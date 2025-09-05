#include<iostream>
#include<vector>
using namespace std;


bool check(vector<int>&nums,int idx,int target,vector<vector<int>>&dp){
    if(target==0) return true;
    if(idx==0) return nums[0]==target;
    if(dp[idx][target]!=-1) return dp[idx][target]; 
    bool nTake=check(nums,idx-1,target,dp);
    bool take=false;
    if(nums[idx]<=target){
   take= check(nums,idx-1,target-nums[idx],dp);

    }
    return dp[idx][target]= take||nTake;

}



bool canPartiation(vector<int>&nums,int n){
    int totalSum=0;
    for(int i=0;i<n;i++){
    totalSum+=nums[i];
    }

    if(totalSum%2!=0) return false;
    int target=totalSum/2;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return check(nums,n-1,target,dp);


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


