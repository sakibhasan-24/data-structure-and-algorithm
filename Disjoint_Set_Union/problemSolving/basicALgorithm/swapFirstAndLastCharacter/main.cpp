/* 
Write a C++ program to exchange 
the first and last characters in a given string and return the result string.

*/


#include <iostream>
#include <string>

using namespace std;

string swapFirstAndLastCharacter(string str) {
    if(str.length() <= 1) {
        return str;
    }
    char temp=str[0];
    str[0]=str[str.length()-1];
    str[str.length()-1]=temp;
    return str;
}
int main() {

    cout<<swapFirstAndLastCharacter("Hello")<<endl;
    cout<<swapFirstAndLastCharacter("Java")<<endl;
    cout<<swapFirstAndLastCharacter("Fail")<<endl;

}