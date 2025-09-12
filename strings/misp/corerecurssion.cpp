//Minimum insertions to make string palindrome
#include<iostream>
#include<algorithm>
using namespace std;

int f(int i,int j,string &s,string &t){
    if(i<0||j<0){
        return 0;
    }
    if(s[i]==t[j]){
      return  1+f(i-1,j-1,s,t);
    }

    return max(f(i-1,j,s,t),f(i,j-1,s,t));


}

int main(){
    string s="leetcode";
    string t=s;
    reverse(t.begin(),t.end());
    int n=s.size();
    int m=t.size();
    int lps=f(n-1,m-1,s,t);
    int ans=n-lps;
    if(ans>0){
        cout<<"The min insertion steps to make string palindrome:"<<" "<<ans;

    }
    else{
        cout<<"The given string is already palindrome";
    }


}