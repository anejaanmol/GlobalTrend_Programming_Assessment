#include <bits/stdc++.h>
using namespace std;


int getMaxDiff(vector<int>&nums){
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>max){
            max=nums[i];
        }
        if(nums[i]<min){
            min=nums[i];
        }
    }
    return max-min;
}
int main(){
    vector<int> nums={5, 8, 13, 14, 15};
    
    int res= getMaxDiff(nums);
    cout<<"Maximum Difference Is: "<<res<<endl;
    return 0;
}