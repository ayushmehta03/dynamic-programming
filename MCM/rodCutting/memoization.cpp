#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// memoization approach 

int f(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
    if(i>j) return 0;
    // overlapping sub problems soln
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=INT_MAX;
    for(int idx=i;idx<=j;idx++){
        int cost=cuts[j+1]-cuts[i-1]+f(i,idx-1,cuts,dp)+f(idx+1,j,cuts,dp);
        mini=min(mini,cost);
    }
    return dp[i][j]= mini;
}

int minCost(int n,int c,vector<int>&cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
    return f(1,c,cuts,dp);


}


int main(){
    int n=7;
    vector<int>cuts={1,3,4,5};
    int c=cuts.size();
    int ans=minCost(n,c,cuts);
    cout<<"The minimu cost incurred is: "<<ans;
    return 0;

}