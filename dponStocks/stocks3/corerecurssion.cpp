#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int f(int idx,int buy,int cap,int n, vector<int>&prices){
    if(idx==n) return 0;
    if(cap==0) return 0;
    int profit;


    if(buy){
    profit=max(-prices[idx]+f(idx+1,0,cap,n,prices),0+f(idx+1,1,cap,n,prices));

    }

    else{
    profit=max(prices[idx]+f(idx+1,1,cap-1,n,prices),0+f(idx+1,0,cap,n,prices));

    }

    return profit;
}

int main(){
    vector<int>prices={3,3,5,0,0,3,1,4};

    int n=prices.size();

    int ans=f(0,1,2,n,prices);

    cout<<"The max profit with at most two trans is:"<<" "<<ans;




}