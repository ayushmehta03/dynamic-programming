#include<iostream>
#include<vector>
using namespace std;

int f(vector<int>&nums,int idx,int target){
    if(target==0) return 1;
    if(idx==0){
        return nums[0]==target;
    }

    int nPick=f(nums,idx-1,target);
    int pick=0;
    if(nums[idx]<=target){
        pick=f(nums,idx-1,target-nums[idx]);
    }

    return pick+nPick;
}


int cntSub(vector<int>&arr,int t, int n){
    return f(arr,n-1,t);
}


int main(){

    vector<int>arr={1,2,2,3};
    int target=3;
    int n=arr.size();
    int ans=cntSub(arr,target,n);
    cout<<"The total no of subset with target sum is: "<<ans;


}