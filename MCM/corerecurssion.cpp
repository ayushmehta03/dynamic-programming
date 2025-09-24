#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int f(int i,int j,vector<int>&arr){
    if(i==j) return 0;


    int mini=1e9;
    for(int k=i;k<j;k++){
    int steps=arr[i-1]*arr[k]*arr[j]+f(i,k,arr)+f(k+1,j,arr);
    if(steps<mini) mini=steps;

    }
    return mini;
}

int matrixCM(vector<int>&arr,int n){

    return f(1,n-1,arr);

}

int main(){
    vector<int>arr={1, 2, 3, 4, 3};
    int n=arr.size();
    int ans=matrixCM(arr,n);
    cout<<"The minimum no of operations is: "<<ans;

    return 0;

}