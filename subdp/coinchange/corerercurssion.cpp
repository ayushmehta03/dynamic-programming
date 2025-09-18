#include<iostream>
#include<vector>
using namespace std;

int f(int idx,vector<int>&arr,int target){

    if(idx==0){
        // if the last index value is completly divisble by the remaining targte 
        // for ex if its 2 and target is so 6%2==0 will return 6/2->no of coins
        if(target%arr[0]==0) return target/arr[0];

        // remove this way not possible by adding max value
        else return 1e9;


    }
    // either we can pick the coin aur not pick 


    // not pick case-> target will not be affected only index will change and no change in number of coins so 0+ recurssive call
    int nPick=0+f(idx-1,arr,target);

    // intialize pick as maximum value
    int pick=1e9;


    //only pick if the value is less than or equal to the target

    if(arr[idx]<=target){
        // we will stay at the index and subtract the target until the upper condition is right
        pick=1+f(idx,arr,target-arr[idx]);

    }


    // return the minimum from both of recurssive call
    return min(pick,nPick);




}


int main(){
    // dominations
    vector<int>arr={5,7,1};

    // target amount
    int target=10;


    // grab the size of dominations array 
    int n=arr.size();

    // passing on the starting index,array and the target
    int ans=f(n-1,arr,target);

    cout<<ans;


}