#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int f(int idx,int buy,int n,vector<int>&prices,vector<vector<int>>&dp){

    // base case
    if(idx>=n) return 0;
    int profit=0;

    // solving overlapping problems
    if(dp[idx][buy]!=-1) return dp[idx][buy];

    if(buy){
        // either will choose to buy or not for each buy conidtion the profit will be negative and after each buy we can't buy until we sell the stocks so buy will be 0
     profit=max(-prices[idx]+f(idx+1,0,n,prices,dp),0+f(idx+1,1,n,prices,dp));
    }

    // selling conidtion only if buy is not applicalble will change the buy state to its orignal after selling again two condiions either sell or not

    else{
        profit=max(prices[idx]+f(idx+2,1,n,prices,dp),f(idx+1,0,n,prices,dp));

    }
    // store the profits in 2d dp array

    return dp[idx][buy]= profit;

}


int main(){

    vector<int>prices={1,2,3,0,2};

    // either buy or not buy starting with buy thats why pass on buy=1;
    
    // starting with index=0,buy=1

    int n=prices.size();


    // declare dp array with nrows and 2 cols cause buy is either 0 or 1 
    vector<vector<int>>dp(n+2,vector<int>(2,-1));
    int ans=f(0,1,n,prices,dp);

    cout<<"The max profit will be :"<<" "<<ans;


}