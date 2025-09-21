#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>&prices,int k){
    int n=prices.size();
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));


       vector<vector<int>>ahead(2,vector<int>(k+1,0));
       vector<vector<int>>curr(2,vector<int>(k+1,0));


       for(int idx=n-1;idx>=0;idx--){
        for(int buy=0;buy<=1;buy++){
            for(int p=1;p<=2;p++){

                if(buy==0){
                curr[buy][p]=max(-prices[idx]+ahead[1][p],ahead[0][p]);

                }

                if(buy==1){
                    curr[buy][p]=max(prices[idx]+ahead[0][p-1],ahead[1][p]);
                }

                

            }
        }
        ahead=curr;
       }

       return ahead[0][k];


}


int main(){
    vector<int>prices={7,1,5,3,6,4};
    int k=2;

    int ans=maxProfit(prices,k);
  cout<<"The max profit with k tanscition will be:"<<" "<<ans;




}
