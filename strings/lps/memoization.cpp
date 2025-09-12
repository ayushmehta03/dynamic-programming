#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j]){
        return 1+f(i-1,j-1,s,t,dp);
    }


    return dp[i][j]= max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));

}



int main(){

    string s= "bbbab";

    string t=s;
    reverse(t.begin(),t.end());

    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n,vector<int>(m+1,-1));
    int ans=f(n-1,m-1,s,t,dp);

    if(ans>0){
    cout<<"The longest common palindromic subsequence is:"<<" "<<ans;
    }


    else{
        cout<<"No common palindromic subsequence";
    }

    return 0;
    





}