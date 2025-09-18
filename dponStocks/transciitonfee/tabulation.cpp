#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int transcitionStock(vector<int>&prices,int fees){
        int n=prices.size();
     vector<vector<int>>dp(n+1,vector<int>(2,0));

     for(int idx=n-1;idx>=0;idx--){
        for(int buy=0;buy<=1;buy++){
            if(buy==0){
                dp[idx][buy]=max(-prices[idx]+dp[idx+1][1],dp[idx+1][0]);

            }
            if(buy==1){
                dp[idx][buy]=max((prices[idx]-fees)+dp[idx+1][0],dp[idx+1][1]);
            }
        }
     }
     return dp[0][0];


}

int main(){
    vector<int>prices={1,3,2,8,4,9};
    int fee=2;

    int ans=transcitionStock(prices,fee);

    cout<<"The max profit after deducting trans fees is:"<<" "<<ans;
    return 0;

}

