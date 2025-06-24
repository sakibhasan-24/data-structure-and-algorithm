/* 
A fixed-size array of buckets
 Each bucket will store a list of key-value pairs (to handle collisions)
 
 structure
    key-value pair

*/

#include<iostream>
#include<vector>    
#include<list>
using namespace std;



struct KeyValue{
    string key;
    int value;

    KeyValue(string k, int v){
        key=k;
        value=v;
    }
};
class HashMap{
    private:
        int SIZE=10;
        vector<list<KeyValue>>table;

        //hash function
        int hash(string key){
            //leet
            int index=0;
            for(int i=0;i<key.length();i++){
                index+=key[i];//leet
            }
            return index%SIZE;
        }
    public:
        HashMap(){
            table.resize(SIZE);
        }
}



int main()

{

}