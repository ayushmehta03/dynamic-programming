#include<iostream>
#include<vector>

using namespace std;



int f(int i,int j,int n,vector<vector<int>>&triangle){

    if(i==n-1) return triangle[n-1][j];

    int dw=triangle[i][j]+f(i+1,j,n,triangle);
    int dg=triangle[i][j]+f(i+1,j+1,n,triangle);
    return min(dw,dg);
}
int main(){
    vector<vector<int>>triangle={
        {2},{3,4},{6,5,7},{4,1,8,3}

    };

    int n=triangle.size();

    int ans=f(0,0,n,triangle);
    cout<<"The triangle min path sum is:"<<" "<<ans;

}