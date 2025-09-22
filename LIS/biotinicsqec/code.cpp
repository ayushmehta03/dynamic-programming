#include<iostream>
#include<vector>
#include<vector>
using namespace std;


int bioS(vector<int>&nums){
    int n=nums.size();

    // frist dp array for storing longest increasing subsequence from 0->n-1
    vector<int>dp1(n,0);

    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
         if(nums[i]>nums[prev] && 1+dp1[prev]>dp1[i]){
            dp1[i]=1+dp1[prev];
         }

        }
    }




    vector<int>dp2(n,0);



}

int main(){
    vector<int>nums={1,11,2,10,4,5,2,1};
    int ans=bioS(nums);
    cout<<ans;

}


