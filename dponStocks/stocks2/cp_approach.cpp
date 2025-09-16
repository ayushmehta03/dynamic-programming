// optimised version of tabulation

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int dpStocks2(vector<int>&prices){
    int n=prices.size();

    vector<vector<int>>dp(n+1,vector<int>(2,0));

    vector<int>ahead(2,0);
    vector<int>curr(2,0);

    ahead[0]=ahead[1]=0;


    int profit=0;

    for(int idx=n-1;idx>=0;idx--){

        for(int buy=0;buy<=1;buy++){
            if(buy==0){
            profit=max(0+ahead[0],-prices[idx]+ahead[1]);
            }

            if(buy==1){
                profit=max(0+ahead[1],prices[idx]+ahead[0]);


            }   
            curr[buy]=profit;
        }
        ahead=curr;

    }
    return curr[0];

}

int main(){
  vector<int>prices={7,1,5,3,6,4};

  int ans=dpStocks2(prices);

  cout<<"The max profit will be:"<<" "<<ans;




}


