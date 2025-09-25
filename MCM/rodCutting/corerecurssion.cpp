#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int f(int i,int j,vector<int>&cuts){
    if(i>j) return 0;
    int mini=INT_MAX;
    for(int idx=i;idx<=j;idx++){
        int cost=cuts[j+1]-cuts[i-1]+f(i,idx-1,cuts)+f(idx+1,j,cuts);
        mini=min(mini,cost);
    }
    return mini;
}

int minCost(int n,int c,vector<int>&cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    return f(1,c,cuts);


}


int main(){
    int n=7;
    vector<int>cuts={1,3,4,5};
    int c=cuts.size();
    int ans=minCost(n,c,cuts);
    cout<<"The minimu cost incurred is: "<<ans;
    return 0;

}