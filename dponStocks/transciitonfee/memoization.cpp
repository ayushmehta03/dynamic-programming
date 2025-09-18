#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int f(int idx,int buy,int n,int fee,vector<int>&prices,vector<vector<int>>&dp){
    if(idx==n) return 0;
    if(dp[idx][buy]!=-1) return dp[idx][buy];
    int profit;
    if(buy==1){
    profit=max(-prices[idx]+f(idx+1,0,n,fee,prices,dp),f(idx+1,1,n,fee,prices,dp));
     
    }
    else{

    profit=max((prices[idx]-fee)+f(idx+1,1,n,fee,prices,dp),f(idx+1,0,n,fee,prices,dp));
    }

    return dp[idx][buy]= profit;


}

int main(){
    vector<int>prices={1,3,2,8,4,9};
    int fee=2;
    int n=prices.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));

    int ans=f(0,1,n,fee,prices,dp);

    cout<<"The max profit after deducting trans fees is:"<<" "<<ans;
    return 0;

}