// tree recursion

// A recursive function that makes more than one recursive call — causing branching like a tree.


// Notify All People in an Area about Electricity Outage
    //1-Goal: Notify everyone in the area about tomorrow’s electricity outage.
    //2-Each person notifies their friends (neighbors, family, colleagues)
    //3-No one should receive the notification more than once//(base case)
    //4-We want to track and output the order in which people got notified.




    #include<iostream>
    #include<vector>
    #include<string>
    #include<unordered_set>
    #include<unordered_map>

    using namespace std;
  unordered_map<string,vector<string>> network;
    void notifyPeople(string people){
        unordered_set<string> notified;
        cout << people << " got notified about electricity outage." << endl;
        if(notified.count(people)){
            return;
        }
        notified.insert(people);//you insert now.find 'you' connected friend
        //you has connection alice,alice has connection charlie,david
        for(size_t i=0;i<network[people].size();i++){
            notifyPeople(network[people][i]);
        }
    }

    int main ()

{
    
  
    network["You"] = {"Alice", "Bob"};
    network["Alice"] = {"Charlie", "David"};
    network["Bob"] = {"Eva", "Frank"};
    network["Charlie"] = {};
    network["David"] = {"Grace"};
    network["Eva"] = {};
    network["Frank"] = {};
    network["Grace"] = {};

    
    notifyPeople("You");
}