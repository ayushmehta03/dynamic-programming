#include<iostream>
#include<vector>
using namespace std;


int rob(vector<int>&nums){
    int prev=nums[0];
    int prev2=0;
    int currI;
    for(int i=1;i<nums.size();i++){
     int pick=nums[i];
     if(i>1) pick+=prev2;
     int nPick=prev;
     prev2=prev;
     currI=max(pick,nPick);
     prev=currI;
    }
    return prev;

}

int robHouse(vector<int>&nums){
    int n=nums.size();
    vector<int>temp1,temp2;
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(nums[i]);
         if(i!=n-1) temp2.push_back(nums[i]);

    }
    int ans=max(rob(temp1),rob(temp2));
    return ans;
}


int main(){

    vector<int>nums={1,2,3,1};
    int ans=robHouse(nums);
    cout<<"The maximum amount of money is:"<<" "<<ans;
    return 0;

}