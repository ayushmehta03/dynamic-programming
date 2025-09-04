#include<iostream>
#include<vector>
using namespace std;

int f(int i, int j1,int j2,int r,int c,vector<vector<int>>&grid){
    if(j1<0||j2<0||j1>=c||j2>=c){
        return -1e8;
    }
    if(i==r-1){
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }

    int maxi=-1e8;
    for(int dj1=-1;dj1<=+1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
        int value=0;
        if(j1==j2) value=grid[i][j1];
        else value=grid[i][j1]+grid[i][j2];
        value+=f(i+1,j1+dj1,j2+dj2,r,c,grid);
        maxi=max(maxi,value);
    }
}
return maxi;
}

int maxChoclate(vector<vector<int>>&grid, int n,int m){
    return f(0,0,m-1,n,m,grid);
}


int main(){
   vector<vector<int>>grid={{2, 0, 0, 0, 0, 0, 2}, {2, 1, 0, 0, 0, 4, 0}, {2, 0, 10, 0, 1, 0, 0}, {0, 3, 0, 6, 5, 0, 0}, {1, 0, 3, 4, 0, 0, 6}};
    int n=grid.size();
    int m=grid[0].size();
    int ans=maxChoclate(grid,n,m);
    cout<<"The max choclate they both can pick is: "<<ans;
    return 0;

}