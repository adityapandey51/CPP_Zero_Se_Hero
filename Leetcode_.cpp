// 191.No. of 1 bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        for(int i=1;i<=32;i++){
            if (n&1){
                count++;
            }
            n=n>>1;
        }
        return count;
    }
};

// 7.Reverse Integer

class Solution {
public:
    int reverse(int x) {
        int ans=0;
        while(x!=0){
            int rem =x%10;
            if ((ans>INT_MAX/10)||(ans<INT_MIN/10)){
                return 0;
            }
            ans=(ans*10)+rem;
            x=x/10;
        }
        return ans;
    }
};

// 9. Palindrome No.

class Solution {
public:
    bool isPalindrome(int x) {
        int ans=0;
        int temp=x;
        if (x<0){
            return false;
        }
        else{
         while(x!=0){
         int rem =x%10;
         if ((ans>INT_MAX/10)||(ans<INT_MIN/10)){
             return false;
         }
         ans=(ans*10)+rem;
         x=x/10;
        }

       return (ans==temp);
        }
       
    }
};

// 1009. compliment of base 10 no. 

class Solution {
public:
    int bitwiseComplement(int n) {
        int m=n;
        int mask=0;

        if (n==0){
            return 1;
        }
        while(m!=0){
            mask =(mask<<1)|1;
            m=m>>1;
        }

        return (~n)&mask;
    }
};

// 231.Power of 2
class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i=0;i<31;i++){
            int ans=pow(2,i);
            if (ans==n){
                return true;
            }

        }
        return false;
    }
};

// 342.Power of 4

class Solution {
public:
    bool isPowerOfFour(int n) {
        for (int i=0;i<=15;i++){
            int a=pow(4,i);
            if (a==n){
                return true;
            }
        }
        return false;
    }
};

// 326.Power of 3

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n==1){
            return true;
        }
        int a=1;
        while(a<=INT_MAX/3){
            a =a*3;
            if (n==a){
                return true;
            }
        }
        return false;
    }
};


// Duplicate in an array

int duplicate(int arr[],int size){
    int ans=0;
    for (int i=0;i<size;i++){
        ans=ans^arr[i];
    }
    for (int j=1;j<size;j++){
        ans=ans^j;
    }
    return ans;
}

// 1207.Given an array of integers arr, return true if the 
// number of occurrences of each value in the array is unique or false otherwise.

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans;
        int size=arr.size();
        int i=0;
        sort(arr.begin(),arr.end());
        while(i<size){
            int count=1;
            for(int j=i+1;j<size;j++){
                if(arr[i]==arr[j]){
                    count++;
                }
                else
                {
                    break;}
            }
            ans.push_back(count);
            i=i+count;
        }
        sort(ans.begin(),ans.end());
        size=ans.size();
        for(int i=0;i<size-1;i++){
            if(ans[i]==ans[i+1]){
                return false;
            }
        }
        return true;
    }
};


// 442.Duplicates in an array
// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant extra space.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i=0;
        vector<int> ans;
        while(i<nums.size()){
            int count=1;
            for (int j=i+1;j<nums.size();j++){
                if (nums[i]==nums[j]){
                    ans.push_back(nums[i]);
                    i++;
                }
            }
        }
        return ans;
    }
};

// another approach -optimized time comp:O(n) space comp:O(1)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector<int> ans;
       for (int i=0;i<nums.size();i++){
           int index=abs(nums[i])-1;
           if (nums[index]<0){
               ans.push_back(index+1);
           }

            nums[index]=nums[index]*(-1);
       }
       return ans;

    }
};


//PROBLEM 852. An array arr is a mountain if the following properties hold: (BINARY SEARCH)
// [PEAK INDEX IN A MOUNTAIN ARRAY]

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0;
        int end=arr.size()-1;
        int mid=start+((end-start)/2);
        while(start<end){
            if (arr[mid]<arr[mid+1]){
                start=mid+1;
            }
            else{
                end= mid;
            }
            mid=start+((end-start)/2);
        }
        return mid;
    }
};


// PROBLEM 69. SQRT(X)

class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        long long int m=s+((e-s)/2);
        int ans;
        while(s<=e){
            long long int sqr=m*m;
            if (sqr>x){
                e=m-1;
            }
            else if(sqr==x){
                return m;
            }
            else{
               ans=m;
               s=m+1;
            }
            m=s+((e-s)/2);
        }
        return ans;
    }
};


double more_precise_sqr_root(int x,int n){
    int tempsol=mysqrt(x);
    double factor=1; 
    double ans=tempsol;
    for (int i=0; i<n;i++){
        factor=factor/10;
        for (double j=0;j*j<x;j=j+factor){
            ans=j;
        }
    }
    return ans;


}

// PROBLEM 1:Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            for (int j=i+1;j<nums.size();j++){
                 if(nums[i]+nums[j]==target){
                     ans.push_back(i);
                     ans.push_back(j);
                     break;
                 }
            }
        }
        return ans;
    }
};



// 88.You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
// and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function,
// but instead be stored inside the array nums1. To accommodate this,
// nums1 has a length of m + n, where the first m elements denote the elements that should be merged,
// and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[i-m];
        }
        sort(nums1.begin(),nums1.end());
    }
};


// 1752.Given an array nums, return true if the array was originally sorted in non-decreasing order,
// then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length
// such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        for (int i=1;i<nums.size();i++){
            if (nums[(i-1)]>nums[i]){
                count++;
            }
        }
        if(nums[nums.size()-1]>nums[0]){
           count++;
        }
        return count<=1;
    }
};


// 189.Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

lass Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        for (int i=0;i<nums.size();i++){
            temp[(i+k)%nums.size()]=nums[i];
        }
        nums=temp;
    }
};


// 283.Given an integer array nums, move all 0's to the end of it while maintaining
// the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s=0;
        for (int j=0;j<nums.size();j++){
            if (nums[j]!=0){
                swap(nums[j],nums[s]);
                s++;
            }
        }
    }
};

 
 

 


