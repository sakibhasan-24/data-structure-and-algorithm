#include<iostream>
#include<vector>
using namespace std;
int factorial(int n){
    //n*n-1;5*

    if(n==0) return 1;
    return n*factorial(n-1);
}

//first iterations
//number =5
//n!=5 so 5*fact(5-1);
                //fact(4)
                    fact(3)
                        fact(2)
                            fact(1)
                                fact(0)==1
//in the stack i put 5,then 4 then 3 then 2 then 1 then 0
//then i start pop 0 ,it return 1 ,the pop 1 it return 1 then pop 2 it return 2 then pop 3 it return 6 then pop 4 it return 24 then pop 5 it return 120


  bool isPowerOfThree(int n) {
     //27/3=9 ,keep 9/3=3
     if(n==0) return false;
     if(n==1) return true;
     if(n%3!=0) return false;
     return isPowerOfThree(n/3);
    }


    vector<int>getNums(vector<int>& digits){
     unordered_set<int> unique;
    for(int i=0;i<digits.size();i++){
        for(int j=0;j<digits.size();j++){
        for(int k=0;k<digits.size();k++){
            if(i!=j &&j!=k && i!=k){
                if(digits[i]!=0){
                int num=digits[i]*100+digits[j]*10+digits[k];
                if(num%2==0){
                    unique.insert(num);
                }
            }
            } 
    }
    }
    }
      return vector<int>(unique.begin(), unique.end());
}
    int totalNumbers(vector<int>& digits) {
        vector<int>ans=getNums(digits);
        return ans.size();
    }

    //1,2,3,4
    //
int main()

{

}