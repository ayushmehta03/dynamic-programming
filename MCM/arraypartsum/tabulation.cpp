#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;




int maxPS(vector<int>&arr,int k){
    int n=arr.size();
    vector<int>dp(n+1,0);


    for(int idx=n-1;idx>=0;idx--){
        int len=0;
        int maxi=INT_MIN;
        int maxiAns=INT_MIN;
        for(int j=idx;j<min(idx+k,n);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi+dp[j+1];
            maxiAns=max(maxiAns,sum);
        }
        dp[idx]=maxiAns;
    }
    return dp[0];


}


int main(){
    vector<int>arr={1,15,7,9,2,5,10};
    int k=3;
    int ans =maxPS(arr,k);
    cout<<"The largest sum will be: "<< ans;
    return 0;

}