/* 
A fixed-size array of buckets
 Each bucket will store a list of key-value pairs (to handle collisions)
 
 structure
    key-value pair

*/

#include<iostream>
#include<vector>    
#include<list>
#include<algorithm>
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
            cout<<"index : "<<index<<endl;
            return index%SIZE;
        }
    public:
        HashMap(){
            table.resize(SIZE);
        }
        //check hashmap is empty or not
        bool isEmpty(){
            // return table.empty();
            for(int i=0;i<SIZE;i++){
                if(!table[i].empty()){
                    return false;
                }
            }
            return true;
        }
        //let's perform insert
        //1->find the index
        // check does this index has any value or not
        //if not then insert the value
        //if value then update
        void insert(string key, int value){
            int index=hash(key);
            cout<<key<<endl;
            // chech value is already exist in table or not
            for(auto it = table[index].begin(); it!=table[index].end();++it){
                if(it->key==key){
                    cout << "Updating  at bucket #" << index << ": (" << key << ", " << value << ")\n";
                    it->value=value;
                    return;
                }
            }

            //if not exist then insert the value
            cout<<"First time create---"<<endl;
           cout << "Inserting at bucket #" << index << ": (" << key << ", " << value << ")\n";
           table[index].push_back({key,value});
        }
        int search(string key){
            int index=hash(key);
            for(auto it=table[index].begin();it!=table[index].end();++it){
                if(it->key==key){
                    cout<<"Found something"<<endl;
                    return it->value;
                }
            }
            cout<<"Not found"<<endl;
            return -1;
        }

        void remove(string key){
            int index=hash(key);
            for(auto it=table[index].begin();it!=table[index].end();it++){
                if(it->key==key){
                    cout<<"Deleting at bucket #"<<index<<": ("<<key<<", "<<it->value<<")"<<endl;
                    // it.key=" ";
                    // it.value=-1;
                    table[index].erase(it);
                    return;
                }
            }
            cout<<"Not found for delete"<<endl;
        }
};



int main()

{
    HashMap mp;
    if(mp.isEmpty()){
        cout<<"hashmap is empty"<<endl;
    }else {
        cout<<"hashmap is not empty"<<endl;
    }
    mp.insert("Mern",2);
    
    mp.insert("Mern",200);
    mp.insert("Nerm",100);
    if(mp.isEmpty()){
        cout<<"hashmap is empty"<<endl;
    }else {
        cout<<"hashmap is not empty"<<endl;
    }
    cout<<mp.search("Mern");
    mp.remove("Mern");
    mp.remove("Nerm");
    if(mp.isEmpty()){
        cout<<"hashmap is empty"<<endl;
    }else {
        cout<<"hashmap is not empty"<<endl;
    }

}