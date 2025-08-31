#include<iostream>
using namespace std;

int f(int i,int j,vector<vector<int>>&obst){
   if(i>=0&&j>=0&&obst[i][j]==1) return 0;
    if(i==0&&j==0) return 1;
    if(i<0 || j<0) return 0;

    int up=f(i-1,j,obst);
    int left=f(i,j-1,obst);
    return up+left;

}

int main(){
    vector<vector<int>>obstaclegrid={
        {0,0,0},{0,1,0},{0,0,0}
    };
    int m=obstaclegrid.size();
    int n=obstaclegrid[0].size();
    
    int ans=f(m-1,n-1,obstaclegrid);
    cout<<"the ways through which we can reach the end without any obstacles: "<<" "<<ans;
    

}

