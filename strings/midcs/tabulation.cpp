#include<iostream>
#include<algorithm>
using namespace std;

//Minimum Insertions/Deletions to Convert String |

int f(string &s,string &t){

    int n=s.size();
    int m=t.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));


    for(int i=0;i<=n;i++) dp[i][0]=0;

    for(int i=0;i<=m;i++) dp[0][i]=0;

    for(int idx=1;idx<=n;idx++){
    for(int idx2=1;idx2<=m;idx2++){
        if(s[idx-1]==t[idx2-1]){
            dp[idx][idx2]=1+dp[idx-1][idx2-1];

        }
        else{
            dp[idx][idx2]=max(dp[idx-1][idx2],dp[idx][idx2-1]);
        }
    
    }
    }
    return dp[n][m];






}




int main(){
    string s="leetcode";
    string t="etco";

    int n=s.size();
    int m=t.size();

    int lcs=f(s,t);

    // total no of operations including deletion and insertion
    int ans=(m+n)-2*lcs;
    cout<<"No of opertaions needed to convert string 1 to string 2 is:"<<" "<<ans;
    return 0;
}