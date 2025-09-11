// same problem optimised with memoization

#include<iostream>
#include<vector>
using namespace std;

string f(string &s,string &t){

    // base case 
    int n=s.size();
    int m=t.size();
  vector<vector<int>>dp(n+1,vector<int>(m+1,0));



    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=m;j++) dp[0][j]=0;


    for(int idx1=1;idx1<=n;idx1++){
        for(int idx2=1;idx2<=m;idx2++){
            if(s[idx1-1]==t[idx2-1]){
                dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
            }

            else dp[idx1][idx2]=max(dp[idx1-1][idx2],dp[idx1][idx2-1]);

        }
    }

    int len=dp[n][m];
    string ans="";
    for(int i=0;i<len;i++){
        ans+='$';
    }

    int index=len-1;

    int i=n,j=m;
    while(i>0 &&j>0){
        if(s[i-1]==t[j-1]){
            ans[index]=s[i-1];
            index--;
            i--;
            j--;
        }

        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    return ans;




}


int main(){
  string text1="abcde";
  string text2="ace";

  int n=text1.size();
  int m=text2.size();



  string ans=f(text1,text2);
   cout<<"The longest common subsequence is:"<<" "<<ans;



}




