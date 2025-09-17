#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProfit(vector<int>&prices,int k){
    int n=prices.size();
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

       for(int idx=n-1;idx>=0;idx--){
        for(int buy=0;buy<=1;buy++){
            for(int p=1;p<=2;p++){

                if(buy==0){
                dp[idx][buy][p]=max(-prices[idx]+dp[idx+1][1][p],dp[idx+1][0][p]);

                }

                if(buy==1){
                    dp[idx][buy][p]=max(prices[idx]+dp[idx+1][0][p-1],dp[idx+1][1][p]);
                }

                

            }
        }
       }

       return dp[0][0][k];


}


int main(){
    vector<int>prices={7,1,5,3,6,4};
    int k=2;

    int ans=maxProfit(prices,k);
  cout<<"The max profit with k tanscition will be:"<<" "<<ans;




}