#include<iostream>
#include<vector>
using namespace std;


bool check(vector<int>&nums,int idx,int target){
    if(target==0) return true;
    if(idx==0) return nums[0]==target;
    bool nTake=check(nums,idx-1,target);
    bool take=false;
    if(nums[idx]<=target){
   take= check(nums,idx-1,target-nums[idx]);

    }
    return take||nTake;

}



bool canPartiation(vector<int>&nums,int n){
    int totalSum=0;
    for(int i=0;i<n;i++){
    totalSum+=nums[i];
    }

    if(totalSum%2!=0) return false;
    int target=totalSum/2;
    return check(nums,n-1,target);


}


int main(){
    vector<int>nums={1,5,11,5};
    int n=nums.size();
    if(canPartiation(nums,n)){
        cout<<"partition sum possible";
    }
    else{
        cout<<"Not possible";
    }
    return 0;
}


