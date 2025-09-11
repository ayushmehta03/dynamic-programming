// same problem optimised with memoization

#include<iostream>
#include<vector>
using namespace std;

int f(string &s,string &t){

    // base case 
    int n=s.size();
    int m=t.size();
  vector<vector<int>>dp(n+1,vector<int>(m+1,0));



    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=m;j++) dp[0][j]=0;

    int ans=0;
    for(int idx1=1;idx1<=n;idx1++){
        for(int idx2=1;idx2<=m;idx2++){
            if(s[idx1-1]==t[idx2-1]){
                dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
                ans=max(ans,dp[idx1][idx2]);
            }

            else dp[idx1][idx2]=0;

        }
    }

    return ans;


}


int main(){
  string text1="abcdxyz";
  string text2="xyzabcd";

  int n=text1.size();
  int m=text2.size();



  int ans=f(text1,text2);
  if(ans) cout<<"The longest common subsequence is:"<<" "<<ans;
    else cout<<"No common subsequence";



}




