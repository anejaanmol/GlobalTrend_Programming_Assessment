// Write a function to check if a given string contains only alphabetic characters.The function should return true if the string contains only alphabetic characters, and false otherwise.
#include <bits/stdc++.h>
using namespace std;

bool AlphabeticCharacter(string& str){
    for(int i=0;i<str.length();i++){
        if( !((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) ){
            return false;
        }
    }
    return true;
}

int main(){
    string str;
    cout<<"Please Enter A string: "<<endl;
    getline(cin, str);
    if(AlphabeticCharacter(str)){
        cout<<"only alphabets are there in the string. "<<endl;
    }else{
        cout<<"the string contains other characters than alphabets";
    }

    return 0;
}