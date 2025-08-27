#include<iostream>
#include<vector>
using namespace std;

int f(int ind,vector<int>&heights,vector<int>&dp,int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int miniSteps=INT_MAX;
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
            int jump=f(ind-j,heights,dp,k) +abs(heights[ind]-heights[ind-j]);
            miniSteps=min(miniSteps,jump);
        }
    }
    return dp[ind]=miniSteps;
}

int main(){
    vector<int>q={10,30,40,50,20};
    int n=q.size();
    int k=3;
    vector<int>dp(n,-1);
    cout<<f(n-1,q,dp,k);

}