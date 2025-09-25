#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int f(int i,int j,vector<int>&nums){
    if(i>j) return 0;
    int maxi=INT_MIN;
    for(int idx=i;idx<=j;idx++){
        int cost=nums[i-1]*nums[idx]*nums[j+1]+f(i,idx-1,nums)+f(idx+1,j,nums);
        maxi=max(maxi,cost);
    }
    return maxi;
}


int maxCoins(vector<int>&nums){
    int n=nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(),1);
    return f(1,n,nums);


}

int main(){
    vector<int>nums={3,1,5,8};
    int ans=maxCoins(nums);
    cout<<"The maximu coins we can earn is: "<<ans;
    return 0;

}