#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int f(int idx,int buy,int n,int fee,vector<int>&prices){
    if(idx==n) return 0;
    int profit;
    if(buy==1){
    profit=max(-prices[idx]+f(idx+1,0,n,fee,prices),f(idx+1,1,n,fee,prices));
     
    }
    else{

    profit=max((prices[idx]-fee)+f(idx+1,1,n,fee,prices),f(idx+1,0,n,fee,prices));
    }

    return profit;


}

int main(){
    vector<int>prices={1,3,2,8,4,9};
    int fee=2;
    int n=prices.size();

    int ans=f(0,1,n,fee,prices);

    cout<<"The max profit after deducting trans fees is:"<<" "<<ans;
    return 0;

}