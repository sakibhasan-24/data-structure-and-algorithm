#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

 int firstUniqChar(string s) {
    unordered_map<char,int>mp;
    for(auto c : s){
        mp[c]++;
    }        
    for(int i=0;i<s.length();i++){
        if(mp.count(s[i])==1){
            return i;
        }
    }
    return -1;
}