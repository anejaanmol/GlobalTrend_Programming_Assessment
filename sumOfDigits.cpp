#include <bits/stdc++.h>
using namespace std;


int sumOfDigits(int n){
    int temp=n;
    int sum=0;
    while(temp){
        int digit=temp%10;
        sum=sum+digit;
        temp/=10;
    }
    return sum;
}
int main(){
    int n;
    cout<<"please enter a number: "<<endl;
    cin>>n;

    int res=sumOfDigits(n);
    cout<<"Sum of Digits Is: "<<res;
    return 0;
}