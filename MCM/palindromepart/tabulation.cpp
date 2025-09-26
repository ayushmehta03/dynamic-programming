#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;




bool isPalindrome(int i,int j,string &s){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int palindromePartition(string &s){
    int n=s.size();
    vector<int>dp(n+1,0);
    
    for(int i=n-1;i>=0;i--){
            int cost=0;
        int minCost=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)) cost=1+dp[j+1];
            minCost=min(minCost,cost);
        }
        dp[i]=minCost;
    }
    return dp[0]-1;

}




int main(){
     string s="aabb";
     int ans=palindromePartition(s);
     cout<<"The min cuts needded for palindorme partioning is: "<<ans;
     return 0;

}