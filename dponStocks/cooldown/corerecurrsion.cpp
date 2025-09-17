#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int f(int idx,int buy,int n,vector<int>&prices){

    // base case
    if(idx>=n) return 0;
    int profit=0;

    if(buy){
        // either will choose to buy or not for each buy conidtion the profit will be negative and after each buy we can't buy until we sell the stocks so buy will be 0
     profit=max(-prices[idx]+f(idx+1,0,n,prices),0+f(idx+1,1,n,prices));
    }

    // selling conidtion only if buy is not applicalble will change the buy state to its orignal with a cool down period after selling again two condiions either sell or not

    else{
        profit=max(prices[idx]+f(idx+2,1,n,prices),f(idx+1,0,n,prices));

    }

    return profit;

}


int main(){

    vector<int>prices={1,2,3,0,2};

    // either buy or not buy starting with buy thats why pass on buy=1;
    
    // starting with index=0,buy=1

    int n=prices.size();

    int ans=f(0,1,n,prices);

    cout<<"The max profit will be :"<<" "<<ans;


}