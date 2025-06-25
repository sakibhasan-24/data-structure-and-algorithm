#include<iostream>
#include<vector>
using namespace std;

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
// nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// 6 vs 3 6 is greater so 6 keep last space.1 2 3 0 0 6
//wholelastindex-- and nums2lastindex also --

// if not ,e:g  2 vs 3 then 3 is greater,so 3 will be 
//[1,3,0]
// [1]
// 1 vs 3 
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int totalSpace=m+n-1;
        int n1=m-1;
        int n2=n-1;

        while(n2>=0){

            if(n1>=0 && nums1[n1]<nums2[n2]){
                nums1[totalSpace]=nums2[n2];
                n2--;
            }else {
                if(n1>=0){
                    nums1[totalSpace]=nums1[n1];
                    n1--;
                }else {
                    if(n2>=0){
                        nums1[totalSpace]=nums2[n2];
                        n2--;
                    }
                }
            }
            totalSpace--;
        }
    }