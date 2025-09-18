#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int transcitionStock(vector<int>&prices,int fees){
        int n=prices.size();

     vector<int>ahead(2,0);
     vector<int>curr(2,0);

     for(int idx=n-1;idx>=0;idx--){
      
            
                curr[0]=max(-prices[idx]+ahead[1],ahead[0]);

            
           
                curr[1]=max((prices[idx]-fees)+ahead[0],ahead[1]);
                ahead=curr;
            
        
     }
     return ahead[0];


}

int main(){
    vector<int>prices={1,3,2,8,4,9};
    int fee=2;

    int ans=transcitionStock(prices,fee);

    cout<<"The max profit after deducting trans fees is:"<<" "<<ans;
    return 0;

}

