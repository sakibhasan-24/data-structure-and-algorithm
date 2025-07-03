/* 


*/
// Scenario:
// You are a receptionist at a small hotel.
// There are 3 available rooms, and 3 guests are arriving.

// Each guest wants to book exactly one room, and no two guests can be in the same room.
/* Goal:
Assign every guest to a unique room in all possible valid ways.

(You don’t know who prefers what room — you just want to try all valid assignments)
Input:
Guests: ["Alice", "Bob", "Charlie"]

Rooms: [101, 102, 103]

output 
Alice → 101, Bob → 102, Charlie → 103  
Alice → 101, Bob → 103, Charlie → 102  
... */


#include <bits/stdc++.h>


using namespace std;



void solve( vector<string>& guests,int index,vector<int>& rooms,unordered_map<string, int> currentAssignment,unordered_set<int> usedRooms,vector<unordered_map<string, int>>& result){

if (index == guests.size()) {
        result.push_back(currentAssignment);
        return;
    }

    string guest=guests[index];
    for(auto room:rooms){
        // if already used then skip it
        if(usedRooms.count(room)) continue;
        // store them {alice:room1}
        currentAssignment[guest]=room;
        usedRooms.insert(room);

        //find next guests
        solve(guests,index+1,rooms,currentAssignment,usedRooms,result);

        //backtrack
        currentAssignment.erase(guest);
        usedRooms.erase(room);

    }
}
vector<unordered_map<string, int>> assignRooms( vector<string>& guests,  vector<int>& rooms){
    vector<unordered_map<string, int>> result;
    unordered_map<string, int> currentAssignment;
    unordered_set<int> usedRooms;

    solve(guests,0,rooms,currentAssignment,usedRooms,result);
    return result;

}
int main()


{
    vector<string> guests = {"Alice", "Bob", "Charlie"};
    vector<int> rooms = {101, 102, 103};

    auto allAssignments = assignRooms(guests, rooms);

    int option = 1;
    for (const auto& assignment : allAssignments) {
        cout << "Option " << option++ << ":\n";
        for (const auto& [guest, room] : assignment) {
            cout << "  " << guest << " -> Room " << room << '\n';
        }
        cout << "-------------------\n";
    }

}