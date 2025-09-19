#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int f(int idx,int previdx,int n, vector<int>&nums){
    if(idx==n) return 0;

    int len=0+f(idx+1,previdx,n,nums);

    if(previdx==-1 || nums[idx]>nums[previdx]){
        len=max(len,1+f(idx+1,idx,n,nums));
    }

    return len;

}

int main(){
    vector<int>nums={10,9,2,5,3,7,101,18};

    int n=nums.size();

    int ans=f(0,-1,n,nums);


    cout<<"the longest increasing subsequence will be:"<<" "<<ans;

}