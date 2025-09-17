#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int f(int idx,int buy,int n,vector<int>&prices,int k,   vector<vector<vector<int>>>&dp){

    if(idx==n) return 0;
    if(k==0) return 0;
    if(dp[idx][buy][k]!=-1) return dp[idx][buy][k];

    int profit;

    if(buy){
    profit=max(-prices[idx]+f(idx+1,0,n,prices,k,dp),f(idx+1,1,n,prices,k,dp));

    }
    else{
        profit=max(prices[idx]+f(idx+1,1,n,prices,k-1,dp),f(idx+1,0,n,prices,k,dp));
    }


    return profit;
}



int main(){
    vector<int>prices={3,2,6,5,0,3};

    int k=2;
    int n=prices.size();
   vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k,-1)));

    int ans=f(0,1,n,prices,k,dp);
    cout<<"The max profit with k tanscition will be:"<<" "<<ans;

}