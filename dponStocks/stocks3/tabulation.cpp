#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dponStocks3(vector<int>&prices){
    int n=prices.size();

    // no base case because it is already filled with zeros and we have to return zero for two cases
   vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int idx=n-1;idx>=0;idx--){
      for(int buy=0;buy<=1;buy++){
        for(int cap=1;cap<=2;cap++){
            if(buy==0){
             dp[idx][buy][cap]=max(-prices[idx]+dp[idx+1][1][cap],0+dp[idx+1][0][cap]);

            }
            if(buy==1){
                dp[idx][buy][cap]=max(prices[idx]+dp[idx+1][0][cap-1],0+dp[idx+1][1][cap]);
            }
        }
      }  
    }
    return dp[0][0][2];



}


int main(){
    vector<int>prices={3,3,5,0,0,3,1,4};

    int n=prices.size();

    int ans=dponStocks3(prices);

    cout<<"The max profit with at most two trans is:"<<" "<<ans;




}