#include<iostream>
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

int f(int i,int n,string &s){
    if(i==n) return 0;
    int minCost=INT_MAX;
    int cost=0;
    for(int j=i;j<n;j++){
        if(isPalindrome(i,j,s)) cost=1+f(j+1,n,s);
        minCost=min(minCost,cost);
    }
    return minCost;
}



int palindromePartition(string &s){
    int n=s.size();
    return f(0,n,s)-1;

}



int main(){
     string s="aabb";
     int ans=palindromePartition(s);
     cout<<"The min cuts needded for palindorme partioning is: "<<ans;
     return 0;

}