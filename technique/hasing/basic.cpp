#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    unordered_map<string,int>storage;
    //keyType,valueType
    //unordered_map<keyType,valueType>name;
    storage["github"]=2;
    storage["leetcode"]=3;
    storage["codechef"]=4;
    storage["codeforces"]=5;
    storage["hackerrank"]=6;

    cout<<storage["leetcode"]<<endl;
    cout<<storage["hackerrank"]<<endl;
    cout<<storage.count("Github")<<endl;
   unordered_map<int,int>freq;
   vector<int>arr={1,2,3,10,10,10,3};
   for(int num:arr){
    freq[num]++;
   cout << "After inserting " << num << ", current map:\n";
    for (auto pair : freq) {
        cout << "key: " << pair.first << " -> value: " << pair.second << endl;
    }
    cout << "------------------------\n";
   }
   cout<<endl;


   string message = "I love coding and I love learning";
    unordered_map<string, int> freq2;
    istringstream split(message);
    for(string word; split >> word;){
        freq2[word]++;
    }

    for(auto pair : freq2) {
        cout << "key: " << pair.first << " -> value: " << pair.second << endl;
    }
}