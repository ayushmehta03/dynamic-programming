#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int dpStocks2(vector<int>&prices){
    int n=prices.size();

    vector<vector<int>>dp(n+1,vector<int>(2,0));

    dp[n][0]=dp[n][1]=0;

    int profit=0;

    for(int idx=n-1;idx>=0;idx--){

        for(int buy=0;buy<=1;buy++){
            if(buy==0){
            profit=max(0+dp[idx+1][0],-prices[idx]+dp[idx+1][1]);
            }

            if(buy==1){
                profit=max(0+dp[idx+1][1],prices[idx]+dp[idx+1][0]);


            }   
            dp[idx][buy]=profit;
        }

    }
    return dp[0][0];

}

int main(){
  vector<int>prices={7,1,5,3,6,4};

  int ans=dpStocks2(prices);

  cout<<"The max profit will be:"<<" "<<ans;




}


