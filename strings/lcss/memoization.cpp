// same problem optimised with memoization

#include<iostream>
#include<vector>
using namespace std;

int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){

    // base case 
    if(i<0 ||j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j]){
        return 1+f(i-1,j-1,s,t,dp);
    }
    return dp[i][j]= max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));


}


int main(){
  string text1="abcde";
  string text2="ace";

  int n=text1.size();
  int m=text2.size();

  vector<vector<int>>dp(n,vector<int>(m,-1));


  int ans=f(n-1,m-1,text1,text2,dp);
  if(ans) cout<<"The longest common subsequence is:"<<" "<<ans;
    else cout<<"No common subsequence";



}




