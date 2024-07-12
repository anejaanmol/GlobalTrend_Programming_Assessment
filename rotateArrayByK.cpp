#include <bits/stdc++.h>
using namespace std;


void reverse( vector<int>&nums, int s,int e){
    while(s<e){
        swap(nums[s++],nums[e--]);
    }
}

void rotate(vector<int>& nums,int k){
    int n=nums.size();
     k=k%n;
    if(k==0) return ;

    reverse(nums,0,n-1);
    reverse(nums, 0, k - 1);
    reverse(nums,k,n-1);
}

void printArray(vector<int>& nums){
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> nums={1,2,3,4,5,6,7,8,9,10};
    int k;
    cout<<"input the value for K: "<<endl;
    cin>>k;
    cout<<"Array Before Rotation: "<<endl;
    printArray(nums);
    rotate(nums,k);
    cout<<"Array After Rotation: "<<endl;
    printArray(nums);


    return 0;
}