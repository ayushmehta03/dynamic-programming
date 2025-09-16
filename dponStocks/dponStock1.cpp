#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int solve(vector<int>&prices){

    // take the size of array
    int n=prices.size();

    // take the min price intially as the first elemnt
    int minPrice=prices[0];
    // let the max profit intially be0
    int maxProfit=0;

    for(int i=1;i<prices.size();i++){

        // calculate the profit by subtacting the purcahed value
        int cost=prices[i]-minPrice;

        // take the maximum for each iteration
        maxProfit=max(maxProfit,cost);

        // the minimum cp should be least to get maxi profit
        minPrice=min(minPrice,prices[i]);
    }

    return maxProfit;


}


int main(){
    vector<int>prices={7,1,5,3,6,4};
    int ans=solve(prices);
    cout<<"Max profit will be:"<<" "<<ans;

}