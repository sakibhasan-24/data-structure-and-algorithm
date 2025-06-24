#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;



//strs = ["eat", "tea", "tan", "ate", "nat", "bat"];

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string s : strs) {
        string key = s;
        cout<<key<<endl;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& pair : mp) {
        result.push_back(pair.second);
    }
    return result;
}
