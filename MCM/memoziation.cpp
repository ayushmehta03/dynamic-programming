#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int f(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int mini=1e9;
    for(int k=i;k<j;k++){
    int steps=arr[i-1]*arr[k]*arr[j]+f(i,k,arr,dp)+f(k+1,j,arr,dp);
    if(steps<mini) mini=steps;

    }
    return dp[i][j]= mini;
}

int matrixCM(vector<int>&arr,int n){
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return f(1,n-1,arr,dp);

}

int main(){
    vector<int>arr={1, 2, 3, 4, 3};
    int n=arr.size();
    int ans=matrixCM(arr,n);
    cout<<"The minimum no of operations is: "<<ans;

    return 0;

}