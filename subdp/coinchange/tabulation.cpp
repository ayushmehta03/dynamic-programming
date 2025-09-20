#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int coinChange(vector<int>&coins,int target){
    int n=coins.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));

    for(int t=0;t<=target;t++){
        if(t%coins[0]==0) dp[0][t]=t/coins[0];

    }

    for(int idx=1;idx<n;idx++){
        for(int t=0;t<=target;t++){
            int nPick=dp[idx-1][t]; 

            int pick=1e9;

            if(coins[idx]>=t){
                pick=dp[idx][t-coins[idx]];

            }

            dp[idx][t]=min(pick,nPick);
        }
    }
    return dp[n-1][target];

}

int main(){

    vector<int>coins={5,7,1};
    int target=10;
    int ans=coinChange(coins,target);
        cout<<ans;


}