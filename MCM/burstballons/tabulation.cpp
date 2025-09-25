#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;



int maxCoins(vector<int>&nums){
    int n=nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(),1);
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    for(int i=n;i>=1;i--){

        for(int j=1;j<=n;j++){
            int maxi=INT_MIN;
            if(i>j) continue;
            for(int idx=i;idx<=j;idx++){
            int cost=nums[i-1]*nums[idx]*nums[j+1]+dp[i][idx-1]+dp[idx+1][j];
            maxi=max(maxi,cost);


            }
            dp[i][j]=maxi;
        }
    }
    return dp[1][n];
}

int main(){
   vector<int>nums={3,1,5,8};
    int ans=maxCoins(nums);
    cout<<"The maximu coins we can earn is: "<<ans;
    return 0; 
}