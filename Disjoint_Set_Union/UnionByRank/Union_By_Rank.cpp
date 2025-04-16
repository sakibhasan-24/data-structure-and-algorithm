// #include<iostream>

// using namespace std;
// // Always connect the smaller group under the bigger one.
// // We use a r[] array to remember how deep a tree is.

// int parent[10];
// int r[10];


// void makeSet(){
//     for(int i=0;i<10;i++){
//         parent[i]=i;
//         r[i]=0;
//     }
// }

// int root(int id){
//     if(parent[id]!=id) {
//         parent[id]=root(parent[id]);
//     }
//     return parent[id];
// }


// void unionNode(int p,int q){
//     int rootp=root(p);
//     int rootq=root(q);
//     if(rootp==rootq) {
//         cout<<"They are already connected!!"<<endl;
//     }
//     if(r[rootp]==0 && r[rootq]==0){
//         parent[rootq]=rootp;
//         r[rootp]++;
       
//     }
//     if(r[rootp]>r[rootq]){
//         parent[rootq]=rootp;
        
//     }
//     if(r[rootp]<r[rootq]){
//         parent[rootp]=rootq;
//     }
// }
// void printArray(int arr[]){
//     for(int i=0;i<10;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }
// int main()


// {
//     makeSet();
//     printArray(parent);

// }

#include<iostream>
using namespace std;

// Always connect the smaller tree under the bigger one.
// Use r[] to keep track of tree depth.

int parent[10];
int r[10];

void makeSet() {
    for (int i = 0; i < 10; i++) {
        parent[i] = i;
        r[i] = 0;
    }
}

// Find root with path compression
int root(int id) {
    if (parent[id] != id) {
        parent[id] = root(parent[id]); // Path compression
    }
    return parent[id];
}

// Union by r
void unionNode(int p, int q) {
    int rootp = root(p);
    int rootq = root(q);

    if (rootp == rootq) {
        cout << "They are already connected!!" << endl;
        return;
    }

    if (r[rootp] < r[rootq]) {
        parent[rootp] = rootq;
    } else if (r[rootp] > r[rootq]) {
        parent[rootq] = rootp;
    } else {
        parent[rootq] = rootp;
        r[rootp]++;
    }
}

void printArray(int arr[]) {
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    makeSet();

    unionNode(1, 9);
    unionNode(8, 9);
    unionNode(2, 8);
    unionNode(1, 2); 

    printArray(parent); 
}
