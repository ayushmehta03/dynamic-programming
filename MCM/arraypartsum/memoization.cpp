#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;




int f(int idx,int n,int k,vector<int>&arr,vector<int>&dp){
    if(idx==n) return 0;
    if(dp[idx]!=-1) return dp[idx];

    int len=0;
    int maxi=INT_MIN;
    int maxAns=INT_MIN;

    for(int j=idx;j<min(idx+k,n);j++){
        len++;
        maxi=max(maxi,arr[j]);
        int cost=len*maxi+f(j+1,n,k,arr,dp);
        maxAns=max(maxAns,cost);

    }
    return  dp[idx]=maxAns;



}

int maxPS(vector<int>&arr,int k){
    int n=arr.size();
    vector<int>dp(n,-1);
    return f(0,n,k,arr,dp);

}


int main(){
    vector<int>arr={1,15,7,9,2,5,10};
    int k=3;
    int ans =maxPS(arr,k);
    cout<<"The largest sum will be: "<< ans;
    return 0;

}