#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int f(int idx,int buy,int n,vector<int>&prices,int k){

    if(idx==n) return 0;
    if(k==0) return 0;

    int profit;

    if(buy){
    profit=max(-prices[idx]+f(idx+1,0,n,prices,k),f(idx+1,1,n,prices,k));

    }
    else{
        profit=max(prices[idx]+f(idx+1,1,n,prices,k-1),f(idx+1,0,n,prices,k));
    }


    return profit;
}



int main(){
    vector<int>prices={3,2,6,5,0,3};

    int k=2;
    int n=prices.size();

    int ans=f(0,1,n,prices,k);
    cout<<"The max profit with k tanscition will be:"<<" "<<ans;

}