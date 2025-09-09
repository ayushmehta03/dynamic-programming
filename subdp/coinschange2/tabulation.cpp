#include<iostream>
#include<vector>
using namespace std;





int cntWays(vector<int>&coins,int amount){
    int n=coins.size();

    vector<vector<int>>dp(n,vector<int>(amount+1,0));
    for(int t=0;t<=amount;t++){
    if(t%coins[0]==0) dp[0][t]=1; 
    }

    for(int idx=1;idx<n;idx++){
        for(int t=0;t<=amount;t++){
            int nPick=dp[idx-1][t];
            int pick=0;
            // infinte pickup
            if(coins[idx]<=t){
                pick=dp[idx][t-coins[idx]];
            }
            dp[idx][t]=pick+nPick;
        }
    }
    return dp[n-1][amount];


}





int main(){
    vector<int>coins={1,2,5};
    int amount=5;
    int ans=cntWays(coins,amount);

    if(ans>0){
            cout<<"The no of combinations will be:"<<" "<<ans;

    }
    else{
        cout<<"No possible combinations";
    }

}