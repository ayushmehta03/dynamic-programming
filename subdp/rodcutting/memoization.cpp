#include<iostream>
#include<vector>
using namespace std;


int f(int idx,int N,vector<int>&price,vector<vector<int>>&dp){
    if(idx==0){
        return N*price[0];
    }
    if(dp[idx][N]!=-1) return dp[idx][N];
    int nTake=0+f(idx-1,N,price,dp);

    int rodLength=idx+1;
    int take=INT_MIN;

    if(rodLength<=N){
        take=price[idx]+f(idx,N-rodLength,price,dp);
    }
    return dp[idx][N]= max(take,nTake);
}



int main(){
    vector<int>price={1, 5, 8, 9, 10, 17, 17, 20};
    int n=price.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));

    int ans=f(n-1,n,price,dp);

    cout<<"The maxi obtainble value is:"<<" "<<ans;



}










