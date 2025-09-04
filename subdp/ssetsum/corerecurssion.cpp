#include<iostream>
#include<vector>
using namespace std;

int f(int index,int target,vector<int>&nums){
    if(target==0) return true;
    if(index==0) return nums[0]==target;
    bool nTake=f(index-1,target,nums);
    bool take=false;
    if(target>=nums[index]){
        take=f(index-1,target-nums[index],nums);
    }
    return take||nTake;
}

int main(){
    vector<int>nums={2,3,1,1};

    int t=4;
    int n=nums.size();
    if(f(n-1,t,nums)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;

}