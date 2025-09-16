#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int f(int idx,int buy,int cap,int n, vector<int>&prices,vector<vector<vector<int>>>&dp){
    if(idx==n) return 0;
    if(cap==0) return 0;

    if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
    int profit;


    if(buy){
    profit=max(-prices[idx]+f(idx+1,0,cap,n,prices,dp),0+f(idx+1,1,cap,n,prices,dp));

    }

    else{
    profit=max(prices[idx]+f(idx+1,1,cap-1,n,prices,dp),0+f(idx+1,0,cap,n,prices,dp));

    }

    return dp[idx][buy][cap]= profit;
}

int main(){
    vector<int>prices={3,3,5,0,0,3,1,4};

    int n=prices.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

    int ans=f(0,1,2,n,prices,dp);

    cout<<"The max profit with at most two trans is:"<<" "<<ans;




}