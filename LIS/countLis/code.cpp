#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




int findNumberOfLIS(vector<int>& nums) {
        // take the szie of array
        int n=nums.size();

        // take varibale maxi for storing the max value from dp array
        int maxi=1;

        // declare two vectors one for stroing longest subsequence and other for counting the no of longest

            vector<int>dp(n,1);
            vector<int>cnt(n,1);


            // traversing via loop

            // starting from the begining to the n-1 element
            for(int i=0;i<n;i++){

                // for keeping the track of previous elements before the current one
                for(int prev=0;prev<i;prev++){

                    // if the current element is greater than the previous and its dp array is holding value which is less than after increasing the previous length value 
                    if(nums[i]>nums[prev] && 1+dp[prev]>dp[i]){
                        dp[i]=1+dp[prev];
                        // inherit the value from previous one
                        cnt[i]=cnt[prev];
                    }

                    // if the dp contains similar value which means it has been encountered before then will increase the count array value
                   else if(nums[i]>nums[prev] &&1+dp[prev]==dp[i]){
                        cnt[i]+=cnt[prev];
                    }


                }
                // take the maximu from the dp array
                maxi=max(maxi,dp[i]);
            }

            // another iteration for getting the counts of the maximum increasing subsequence 

            int ans=0;
        for(int i=0;i<n;i++){
            // if we get the maxi in the dp array we will retun cnt from the sae position 
            if(dp[i]==maxi) ans+=cnt[i];
        }
        return ans;

    }








int main(){
    vector<int>nums={1,3,5,4,7};

    int ans=findNumberOfLIS(nums);

    cout<<"The num of longest increasing subsequence is:"<<" "<<ans;
    


}