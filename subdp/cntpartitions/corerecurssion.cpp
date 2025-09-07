#include<iostream>
#include<vector>
using namespace std;


int f(vector<int>&nums,int target,int idx){
    if(idx==0){
        if(target==0 &&nums[0]==target) return 2;
        if(target==0 ||nums[0]==target ) return 1;
        else return 0;
    }

    int nottake=f(nums,target,idx-1);
    int take=0;
    if(nums[idx]<=target){
        take=f(nums,target-nums[idx],idx-1);
    }
    return take+nottake;

}

int findWays(vector<int>&nums,int tar){
    int n=nums.size();

    return f(nums,tar,n-1);


}

int main(){
    vector<int>arr={5, 2, 6, 4};
    int d=3;
    int ts=0;

    for(auto &it:arr) ts+=it;

    if(ts-d<0 || (ts-d)%2) return false;
    int ans=findWays(arr,(ts-d)/2);
    if(ans>0){
    cout<<"The possibe partiations with difference "<< ""<< d<<" is: "<<ans;
    }
    else{
        cout<<"No pair with difference "<<d;
    }



}