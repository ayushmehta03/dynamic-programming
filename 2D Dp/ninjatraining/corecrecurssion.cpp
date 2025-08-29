#include<iostream>
#include<vector>
using namespace std;

int f(int day,int last,vector<vector<int>>&points){
    if(day==0){
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<=2;i++){
        if(i!=last){
            int point=points[day][i]+f(day-1,i,points);
          maxi=max(maxi,point);

        }
    }
    return maxi;

}

int ninjaTraining(vector<vector<int>>&points,int n){

    return f(n-1,3,points);

}


int main(){
    vector<vector<int>> points = {{10, 40, 70},
                                 {20, 50, 80},
                                 {30, 60, 90}};
     int n=points.size();
     cout<<ninjaTraining(points,n);


}
