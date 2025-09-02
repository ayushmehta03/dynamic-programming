#include<iostream>
#include<vector>
using namespace std;


int f(int i,int j,vector<vector<int>>&matrix){
    if(j<0 || j>=matrix[0].size()) return 1e8;
    if(i==0) return matrix[0][j];

    int up=matrix[i][j]+f(i-1,j,matrix);

    int ld=matrix[i][j]+f(i-1,j-1,matrix);
    int rd=matrix[i][j]+f(i-1,j+1,matrix);

    return min(up,min(ld,rd));
}



int minFallingSum(vector<vector<int>>&matrix){
        int n=matrix.size();
    int m=matrix[0].size();
    int mini=1e8;
    for(int j=0;j<m;j++){
    mini=min(mini,f(n-1,j,matrix));
    }
      return mini;

}

int main(){
    vector<vector<int>>matrix={
        {2,1,3},{6,5,4},{7,8,9}
    };

    int ans=minFallingSum(matrix);
    cout<<"The minimu falling sum will be :"<<" "<<ans;
    return 0;
}