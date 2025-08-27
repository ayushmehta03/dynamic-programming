#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>&nums){
    int n=nums.size();

    int prev=nums[0];
    int prev2=0;

    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1) take+=prev2;
        int nTake=prev;
        int currI=max(take,nTake);

        prev2=prev;
        prev=currI;
    }
    return prev;

}

int main(){

    vector<int>nums={2,7,9,3,1};

    int ans=rob(nums);
    cout<<"The maximun amount of money that can be robbed is:"<<" "<<ans;


}