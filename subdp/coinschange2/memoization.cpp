#include<iostream>
#include<vector>
using namespace std;

int f(int idx,vector<int>&coins,int amount,vector<vector<int>>&dp){
    if(idx==0){
        if(amount%coins[0]==0) return 1;
        else return 0;
    }

    if(dp[idx][amount]!=-1) return dp[idx][amount];

    int nPick=f(idx-1,coins,amount,dp);
    int pick=0;
    if(coins[idx]<=amount){
        pick=f(idx,coins,amount-coins[idx],dp);
    }

    return dp[idx][amount]= pick+nPick;
}





int main(){
    vector<int>coins={1,2,5};
    int amount=5;
    int n=coins.size();
     vector<vector<int>>dp(n,vector<int>(amount+1,-1));

    int ans=f(n-1,coins,amount,dp);

    if(ans>0){
            cout<<"The no of combinations will be:"<<" "<<ans;

    }
    else{
        cout<<"No possible combinations";
    }

}