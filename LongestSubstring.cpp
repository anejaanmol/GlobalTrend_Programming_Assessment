#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(const string& str) {
    unordered_map<char, int> IndexMap;
    int maxLength = 0;
    int s = 0;

    for (int e = 0; e < str.length(); ++e) {
        char currChar = str[e];

        if (IndexMap.find(currChar) != IndexMap.end()) {
            s = max(s, IndexMap[currChar] + 1);
        }

        IndexMap[currChar] = e;
        maxLength = max(maxLength, e - s + 1);
    }

    return maxLength;
}
int main(){

    string str;
    cout<<"Enter STRING Please: "<<endl;
    cin>>str;
    cout<<"Longest Substring IS: "<<lengthOfLongestSubstring(str)<<endl;
    return 0;
}