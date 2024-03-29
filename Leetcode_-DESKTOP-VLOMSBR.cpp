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

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        for (int i=0;i<nums.size();i++){
            temp[(i+k)%nums.size()]=nums[i];
        }
        nums=temp;
    }
};

//inplace sol.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       k %=nums.size();
       reverse(nums,0,nums.size()-1);
       reverse(nums,0,k-1);
       reverse(nums,k,nums.size()-1);
    }

private:
    void reverse(vector<int> &nums,int l,int r){
        while(l<r){
            swap(nums[l++],nums[r++]);
        }
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



// 344.Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

class Solution {
public:
    void reverseString(vector<char>& s) {
        int st=0;
        int e=s.size()-1;
        while(st<=e){
            swap(s[st],s[e]);
            st++;
            e--;
        }
    }
};

// REPLACE SPACES

#include <bits/stdc++.h> 
string replaceSpaces(string &str){
	string temp="";
	for (int i=0;i<str.length();i++){
		if(str[i]==' ' || str[i]=='\0'){
           temp.push_back('@');
		   temp.push_back('4');
		   temp.push_back('0');
		}
		else{
			temp.push_back(str[i]);
		}
	}
	return temp;
}

// 1910:
// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)<s.length()){
            s.erase(s.find(part),part.size());
        }
        return s;
    }
};

// 567:
// PERMUTATIONS OF A STRING
// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

class Solution {
private:
    bool check_equal(int count1[26],int count2[26]){
        for (int i=0;i<26;i++){
            if (count1[i]!=count2[i]){
                return 0;
            }
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int count1[26]={0};
        for(int i=0;i<s1.length();i++){
           int index=s1[i]-'a';
           count1[index]++;
        }

        int i=0;
        int window_length=s1.length();
        int count2[26]={0};
        while(i<window_length && i<s2.length()){
            int index=s2[i]-'a';
            count2[index]++;
            i++;
        }

        if(check_equal(count1,count2)){
            return 1;
        }
        while(i<s2.length()){
           char newchar=s2[i];
           int index=newchar-'a';
           count2[index]++;

           char oldchar=s2[i-window_length];
           index=oldchar-'a';
           count2[index]--;
           i++;
           if(check_equal(count1,count2)){
               return 1;
           }
        }
        return 0;
    }
};


// 1047:remove all adjacent duplicate elements

// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique. 
 
//  tle problem
 class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
        while(s.length()>=2 && i<s.length() ){
           if (s[i]==s[i+1]){
               s.erase(i,2);
               i=0;
           }else{
               i++;
           }
        }
        return s;
    }
};


class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> a;
        for (int i=0;i<s.length();i++){
            if (a.size()==0){
                a.push_back(s[i]);
            }
            else{
                if(a.back()==s[i]){
                    a.pop_back();
                }
                else{
                    a.push_back(s[i]);
                }
            }
        }
        string temp="";
        for (int i=0;i<a.size();i++){
            temp.push_back(a[i]);
        }
        return temp;
    }
};


 
// 443.string compression

class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int ansIndex=0;
        int n=chars.size();
        while(i<n){
            int j=i+1;
            while(j<n && chars[i]==chars[j]){
                j++;
            }
            int count=j-i;
            chars[ansIndex++]=chars[i];
            if (count>1){
                string cnt=to_string(count);
                for(char ch:cnt){
                    chars[ansIndex++]=ch;
                }
            }
            i=j;
        }
        return ansIndex;
    }
};

// 54.spiralwave

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        int startingrow=0;
        int endingrow=row-1;
        int startingcol=0;
        int endingcol=col-1;

        int count=0;
        int total=row*col;
        vector<int> ans;
        while(count<total){
            for (int i=startingcol;(count<total)&&(i<=endingcol);i++){
                ans.push_back(matrix[startingrow][i]);
                count++;
            }
            startingrow++;
            for (int i=startingrow;(count<total)&&(i<=endingrow);i++){
                ans.push_back(matrix[i][endingcol]);
                count++;
            }
            endingcol--;
            for (int i=endingcol;(count<total)&&(i>=startingcol);i--){
                ans.push_back(matrix[endingrow][i]);
                count++;
            }
            endingrow--;
            for (int i=endingrow;(count<total)&&(i>=startingrow);i--){
                ans.push_back(matrix[i][startingcol]);
                count++;
            }
            startingcol++;
        }        
       return ans;
    }
};

// WAVE PATTERN

#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    int i=0;
    vector<int> ans;
    while(i<mCols){
        int j;
        if (i%2==0){
           j=0;
        }else{
           j=nRows-1;
        }
       while(j<nRows && j>=0){
         ans.push_back(arr[j][i]);
          if (i%2==0){
             j++;
          }else{
            j--;
          }
       }
       i++;
   }
   return ans;
}


// 48.Rotate image

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      for (int i=0;i<matrix.size()-1;i++){
          for (int j=i+1;j<matrix.size();j++){
             swap(matrix[i][j],matrix[j][i]);
          }
      }
      for (int i=0;i<matrix.size();i++){
          int s=0;
          int e=matrix.size()-1;
          while(s<=e){
              swap(matrix[i][s],matrix[i][e]);
              s++;
              e--;
          }
      }
    }
};

// 74.SEARCH IN A MATRIX
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int row=matrix.size();
       int col=matrix[0].size();

       int s=0;
       int e=row*col-1;
       int mid=s+((e-s)/2);
       while(s<=e){
           int element=matrix[mid/col][mid%col];
           if(target==element){
               return true;
           }else if(target>element){
               s=mid+1;
           }else{
               e=mid-1;
           }
            mid=s+((e-s)/2);
       }
       return false;
    }
};

// 240.SEARCH IN A MATRIX II
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int r=0;
        int c=col-1;
        while(r<row && c>=0){
            if(matrix[r][c]==target) return true;
            matrix[r][c]<target?r++:c--;
        }
        return false;
    }
};

// 204:Given an integer n, return the number of prime numbers that are strictly less than n.{COUNT PRIMES}
// TIME COMPLEXITY:O(Nlog(log(n))) sum of harmonic progression.
// SIEVE OF ERATOSTHENES
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1,true);
        prime[0]=prime[1]=false;
        int count=0;
        for (int i=2;i<n;i++){
            if (prime[i]){
                count++;
                for (int j=2*i;j<n;j=j+i){
                    prime[j]=false;
                }
            }
        }
        return count;
    }
};


50:Pow(x,n)

class Solution {
public:
    double myPow(double x, int n) {
        // double s=x;
        // int absin=abs(n);
        // for (int i=0;i<absin-1;i++){
        //     x=x*s;
        // }

        // if (n<0) {
        //    return 1/x;
        // }
        // else if(n==0) return 1.0;
        return pow(x,n);
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        long long int k=abs(n);
        double ans=1.0;
        if(n==0) return 1.0;
        if(x==1.0) return x;
        while(k>0)
        {
            // ans=ans*x;
            // k--;
            if(k%2){ ans=ans*x; k--;}
            else{ x=x*x; k=k/2;}
        }
        if(n<0)
        {
            double p=(double)(1.0)/(double)(ans);
            return p;
        }
        
        return ans;    
    }
};

// 41:first missing positive

class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        for(int i = 0; i < A.size(); i++)
            while(A[i] > 0 && A[i] <= A.size() && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);
        
        for(int i = 0; i < A.size(); i++)
            if(A[i] != i + 1)
                return i + 1;
        
        return A.size() + 1;
    }
};

// 35:SEARCH INSERT POSITION
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+((e-s)/2);
        while(s<=e){
            if (nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                s=mid+1;
                }
            else{
                e=mid-1;
            }
            mid=s+((e-s)/2);
        }
        return mid;
    }
};

// 28:FIND THE INDEX OF FIRST OCCURENCE IN A STRING
// Given two strings needle and haystack,
// return the index of the first occurrence of needle in haystack,
// or -1 if needle is not part of haystack.

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans=haystack.find(needle);
        if(ans>=0 && ans<haystack.length()){
            return ans;
        }
        return -1;
    }
};

// 27.REMOVE ELEMENT
// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
// Return k.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            if(nums[s]==val && nums[e]!=val){
                swap(nums[s],nums[e]);
                s++;
                e--;
            }else if(nums[s]!=val && nums[e]==val){
                s++;
                e--;
            }else if(nums[s]!=val && nums[e]!=val){
                s++;
            }else{
                e--;
            }
        }
        int k;
        for (int i=0;i<nums.size();i++){
            if(nums[i]==val){
                k=i;
                break;
            }
        }
        nums.erase(nums.begin()+k,nums.end());
        return nums.size();
    }
};

// 2108:FIND FIRST PALINDROMIC IN AN ARRAY
// Given an array of strings words, return the first palindromic string in the array.
//  If there is no such string, return an empty string "".
// A string is palindromic if it reads the same forward and backward.

class Solution {
private:
    bool isPalindromic(string word){
        string temp="";
        for (int i=word.length()-1;i>=0;i--){
            temp.push_back(word[i]);
        }
        if(temp==word){
            return true;
        }
        return false;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for (int i=0;i<words.size();i++){
            if(isPalindromic(words[i])){
                return words[i];
            }
        }
        return "";
    }
};

// 2nd method:
class Solution {
private:
    bool isPalindromic(string word){
        int s=0;
        int e=word.length()-1;
       while(s<=e){
           if(word[s]!=word[e]){
               return false;
           }
           s++;
           e--;
       }
       return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for (int i=0;i<words.size();i++){
            if(isPalindromic(words[i])){
                return words[i];
            }
        }
        return "";
    }
};

// 33:SEARCH IN ROTATED SORTED ARRAY

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>=nums[i]){
                if(target>=nums[i]&& target<nums[mid]){
                    j=mid-1;
                }
                else
                    i=mid+1;
            }
            else if(nums[mid]<=nums[j]){
                if(target>nums[mid]&&target<=nums[j])
                    i=mid+1;
                else
                j=mid-1;
            }
        }
        return -1;
    }
};

// 153:Find minimum in rotated sorted array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+((e-s)/2);
        while(s<e){
            if(nums[s] <= nums[e]) return nums[s];
            if (nums[mid]>=nums[0]){
                s=mid+1;
            }else{
                e=mid;
            }
            mid=s+((e-s)/2);
        }
        return nums[mid];
        
    }
};


// Given an array of integers nums, calculate the pivot index of this array.
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
// Return the leftmost pivot index. If no such index exists, return -1.
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for (int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        int left=0;
        int right=sum;
        for (int i=0;i<nums.size();i++){
            right-=nums[i];
            if(left==right) return i;
            left+=nums[i];
        }
        return -1;
    }
};

// 4.Median of two sorted arrays
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        vector<int> ans;
        while(i<nums1.size() && j<nums2.size()){
            if (nums1[i]>nums2[j]){
                ans.push_back(nums2[j]);
                j++;
            }else if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums1[i]);
                ans.push_back(nums2[j]);
                i++;
                j++;
            }
        }
        while(i<nums1.size()){
            ans.push_back(nums1[i]);
            i++;
        }
         while(j<nums2.size()){
            ans.push_back(nums2[j]);
            j++;
        }

        if (ans.size() &1){
            return ans[ans.size()/2];
        }else{
            double l=ans[(ans.size()/2)-1];
            double r=ans[(ans.size()/2)];
            double avg=(l+r)/2;
            return avg;

        }
        
    }
};

//509.fibonacci number using recursion

class Solution {
public:
    int fib(int n) {
        if (n==0||n==1) return n;
        return fib(n-1)+fib(n-2);
    }
};

//15.3Sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size()<3) return {};
        sort(nums.begin(),nums.end());
        for (int i=0;i+2<nums.size();i++){
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
           int l=i+1;
           int r=nums.size()-1;
           while(l<r){
               int sum=nums[i]+nums[l]+nums[r];
               if (sum==0){
                    ans.push_back({nums[i], nums[l++], nums[r--]});
                    while (l < r && nums[l] == nums[l - 1])
                        ++l;
                    while (l < r && nums[r] == nums[r + 1])
                        --r;
                }else if(sum<0){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
};


//78.subsets

class Solution {
private:
    void solve(vector<int> nums,vector<int> output,int index,vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        solve(nums,output,index+1,ans);

        int element=nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        solve(nums,output,index,ans);
        return ans;
    }
};

//17.Letter combinations of a phone number.
class Solution {
private:
    void solve(string digits,string output,int index,vector<string>& ans,string mapping[]){
        if (index>=digits.length()){
            ans.push_back(output);
            return;
        }
        int number=digits[index]-'0';
        string value=mapping[number];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,output,index+1,ans,mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;
        string output;
        int index=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,index,ans,mapping);
        return ans;
    }
};


//46.Permutations
//Given an array nums of distinct integers, 
// return all the possible permutations. You can return the answer in any order.

class Solution {
private:
    void solve(vector<int> nums,vector<vector<int>>& ans,int index){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for (int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        solve(nums,ans,index);
        return ans;
    }
};


//26.Remove Duplicates from a sorted array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0) return 0;
        int i=1;
       while(i<nums.size()){
            if(nums[i]!=nums[i-1]){
                i++;
            }else{
                nums.erase(nums.begin()+i);
            }
        }
        return nums.size();
    }
};

//29.DIVIDE TWO INTEGERS
//Given two integers dividend and divisor,
//divide two integers without using multiplication, division, and mod operator.

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }

        const int sign=(dividend>0 ^ divisor>0)?-1:1;

        long did=labs(dividend);
        long div=labs(divisor);
        long ans=0;

        while(did>=div){
            long k=1;
            while(k*2*div<=did){
                k*=2;
            }
            did-=(k)*div;
            ans+=k;
        }
        return ans*sign;
    }
};


//34.first and last position of an element.
class Solution {

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int l = ranges::lower_bound(nums, target) - nums.begin();
        if (l == nums.size() || nums[l] != target)
            return {-1, -1};
        const int r = ranges::upper_bound(nums, target) - nums.begin() - 1;
        return {l, r};
    }
};

//14.LONGEST COMMON PREFIX

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        for (int i=0;i<strs[0].length();i++){
            for (int j=1;j<strs.size();j++){
                if(i==strs[j].length()||strs[j][i]!=strs[0][i]){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};

//59.Spiral matrix II

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        int startingrow=0;
        int endingrow=n-1;
        int startingcol=0;
        int endingcol=n-1;

        int count=1;
        int total=n*n;
        vector<vector<int>> ans(n,vector<int>(n));
        while(count<=total){
            for (int i=startingcol;(count<=total)&&(i<=endingcol);i++){
                ans[startingrow][i]=count++;       
            }
            startingrow++;
            for (int i=startingrow;(count<=total)&&(i<=endingrow);i++){
                ans[i][endingcol]=count++;
            }
            endingcol--;
            for (int i=endingcol;(count<=total)&&(i>=startingcol);i--){
               ans[endingrow][i]=count++;
            }
            endingrow--;
            for (int i=endingrow;(count<=total)&&(i>=startingrow);i--){
                ans[i][startingcol]=count++;
            }
            startingcol++;
        }        
       return ans;
    }
};

//21.MERGE TWO SORTED LISTS
/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2)
            return list1 ? list1 : list2;
        if (list1->val > list2->val)
            swap(list1, list2);
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
};


//24.SWAP NODES IN PAIRS

/*
Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes
(i.e., only nodes themselves may be changed.)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    int getLength(ListNode* &head){
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0,head);
        ListNode* prev=&dummy;
        ListNode* curr=head;
        const int length=getLength(head);

        for (int i=0;i<length/2;i++){
            ListNode* temp=curr->next;
            curr->next=temp->next;
            temp->next=prev->next;
            prev->next=temp;
            prev=curr;
            curr=curr->next;
        }

        return dummy.next;
    }
};

//206.REVERSE LINKED LIST

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    void reverse(ListNode* &head,ListNode* curr,ListNode* prev){
        if(curr==NULL){
            head=prev;
            return;
        }

        ListNode* forward=curr->next;
        curr->next=prev;
        reverse(head,forward,curr);
    }
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        reverse(head,curr,prev);
        return head;
    }
};

//876: MIDDLE OF LINKED LIST

// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head==NULL || head->next==NULL){
            return head;
        }

        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }
};

//25.Reverse in K Groups;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
  ListNode* reverse(ListNode* head, ListNode* tail) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != tail) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       if (head == nullptr)
      return nullptr;

    ListNode* tail = head;

    for (int i = 0; i < k; ++i) {
      if (tail == nullptr)
        return head;
      tail = tail->next;
    }

    ListNode* newHead = reverse(head, tail);
    head->next = reverseKGroup(tail, k);
    return newHead;
    }
};


//141. LinkedList cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==NULL) return false;
        map<ListNode*,bool> mp;

        ListNode* temp=head;

        while(temp!=NULL){
            if (mp[temp]==true) return true;
            mp[temp]=true;
            temp=temp->next;
        };

        return false;

    }
};

//142.Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

//Do not modify the linked list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head==NULL) return nullptr;

        map<ListNode*,bool> mp;

        ListNode* temp=head;
        while(mp[temp]!=true && temp!=NULL){
            mp[temp]=true;
            temp=temp->next;
        }
        return temp;
    }
};


//83. remove duplicates from sorted lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr) {
            while (curr->next && curr->val == curr->next->val)
                curr->next = curr->next->next;
            curr = curr->next;
        }

        return head;
    }
};


//148.SORT LIST

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* Mid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* mergeSortedLists(ListNode* p1,ListNode* p2){
        if (p1==NULL || p2==NULL){
            return ((p1==NULL)?p2:p1);
        }
        ListNode* ans=new ListNode(0);
        ListNode* curr=ans;

        while(p1!=NULL && p2!=NULL){
            if (p1->val < p2->val){
                curr->next=p1;
                p1=p1->next;
            }else{
                curr->next=p2;
                p2=p2->next;
            }
            curr=curr->next;
        }
        if(p1!=NULL || p2!=NULL){
            curr->next=((p1!=NULL)?p1:p2);
        }
        return ans->next;
    }
   
public:
    ListNode* sortList(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;

        ListNode* mid=Mid(head);
        ListNode* newHead=mid->next;
        mid->next=NULL;

        ListNode* leftHalf=sortList(head);
        ListNode* rightHalf=sortList(newHead);
        return mergeSortedLists(leftHalf,rightHalf);
    }
};

//75.SORT COLORS

class Solution {
public:
    void sortColors(vector<int>& nums) {
       int l=0;
       int r=nums.size()-1;
       for(int i=0;i<=r;){
           if (nums[i]==0){
               swap(nums[i++],nums[l++]);
           }else if(nums[i]==1){
               i++;
           }else{
               swap(nums[i],nums[r--]);
           }
       }
    }
};

//234.PALINDROME LINKED LIST

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverse(ListNode* slow){
        ListNode* curr=slow;
        ListNode* prev=NULL;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return false;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        if (fast){
            slow=slow->next;
        }
        slow=reverse(slow);

        while(slow){
            if (slow->val!=head->val){
                return false;
            }
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
};

----------------------------------------------------------------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* add(ListNode* l1,ListNode* l2){
        int carry=0;
        ListNode* ans=new ListNode(0);
        ListNode* curr=ans;
        while(l1 && l2){
            int ans=l1->val+l2->val+carry;
            int digit=ans%10;
            curr->next=new ListNode(digit);
            carry=ans/10;
            l1=l1->next;
            l2=l2->next;
            curr=curr->next;
        }
        while(l1){
            int ans=l1->val+carry;
            int digit=ans%10;
            curr->next=new ListNode(digit);
            carry=ans/10;
            l1=l1->next;
            curr=curr->next;
        }
        while(l2){
            int ans=l2->val+carry;
            int digit=ans%10;
            curr->next=new ListNode(digit);
            carry=ans/10;
            l2=l2->next;
            curr=curr->next;
        }
        if(carry){
            curr->next=new ListNode(carry);
        }
        ListNode* head=ans->next;
        ans->next=NULL;
        return head;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {  
        ListNode* ans=add(l1,l2);
        return ans;
    }
};

--------------------------------------------------------------------------------------------------
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       Node* temp=head;
       Node* ans=new Node(0);
       Node* curr=ans;
       while(temp){
           curr->next=new Node(temp->val);
            curr=curr->next;
            temp=temp->next;
       } 
       temp=head;
       curr=ans->next;
       map<Node*,Node*> mp;

       while(temp){
          mp[temp]=curr;
          temp=temp->next;
          curr=curr->next; 
       }

       curr=ans->next;
       temp=head;
        while(curr){
            curr->random=mp[temp->random];
            curr=curr->next;
            temp=temp->next;
        }

       return ans->next;
    }
};

//WE CAN ALSO DO IN O(1) S.C
//WITHOUT USING MAP

-------------------------------------------------------------------------------------
//2095.DELETE THE MIDDLE NODE OF LINKED LIST

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head==NULL || head->next==NULL) return nullptr;
        ListNode* slow=head;
        ListNode* prev=NULL;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        slow->next=NULL;        
        return head;
    }
};

//20.Valid parenthesis

class Solution {
public:
    bool isValid(string s) {
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if (ch=='{' || ch=='[' || ch=='('){
            st.push(ch);
        } else {
            if (!st.empty()) {
              char top = st.top();
              if (ch == '}' && top == '{') {
                st.pop();
              } else if (ch == ']' && top == '[') {
                st.pop();
              } else if (ch == ')' && top == '(') {
                st.pop();
              } else {
                return false;
              }
            } else {
              return false;
            }
        }
    }
    return st.empty();
    }
};

---------------------------------------------------------------------------------------
//84.largest rectangle in histogram

class Solution {
private:
    vector<int> nextSmaller(vector<int>& heights){
        stack<int> s;
        s.push(-1);
        vector<int> ans(heights.size());
        for(int i=heights.size()-1; i>-1; i--){
            int num=heights[i];
            while(s.top()>-1 && heights[s.top()]>=num){
                s.pop();
            }   
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
     vector<int> beforeSmaller(vector<int>& heights){
        stack<int> s;
        s.push(-1);
        vector<int> ans(heights.size());
        for(int i=0; i<heights.size();i++){
            int num=heights[i];
            while(s.top()>-1 && heights[s.top()]>=num){
                s.pop();
            }   
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next;
        next=nextSmaller(heights);
        vector<int> prev;
        prev=beforeSmaller(heights);
        int ans=INT_MIN;

        for(int i=0;i<heights.size();i++){
            int length=heights[i];
            int n=next[i];
            int p=prev[i];
            if (next[i]==-1){
                n=heights.size();
            }
            int breadth=n-p-1;
            int area=length*breadth;
            ans=max(ans,area);
        }
        return ans;
    }
};

-----------------------------------------------------------------------------------------
1351.Count negetive numbers in a sorted MATRIX

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int i=rows-1;
        int j=0;
        int ans=0;

        while(i>=0 && j<cols){
            if(grid[i][j]<0){
                ans += cols-j;
                i--;
            }else{
                j++;
            }
        }
        return ans;
    }
};
----------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------
                                  TREES

222.COUNT COMPLETE TREE NODES

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void hello(TreeNode* root,int &count){
       if(root==NULL){
           return;
       }
        hello(root->left,count);
        count++;
        hello(root->right,count);
    }
public:
    int countNodes(TreeNode* root) {
        int count=0;
        hello(root,count);
        return count;
    }
};

-------------------------------------------------------------------------------------------------------

// 941.//  Given an array of integers arr, return true if and only if it is a valid mountain array.

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1;
        int mid=s+((e-s)/2);
        int peak=-1;
        if (arr.size()<3) return false;
        while(s<e){
            if(arr[mid]==arr[mid+1]){
                return false;
            }else if(arr[mid]>arr[mid+1]){
                peak=mid;
                e=mid;
            }else{
                s=mid+1;
            }
            mid=s+((e-s)/2);
        } 
        if(peak==0 || peak==arr.size()-1 || peak ==-1){
            return false;
        }  
        for (int i=0;i<peak;i++){
            if(arr[i]>=arr[i+1]){
                return false;
            }
        }
        for (int i=peak;i<arr.size()-1;i++){
            if(arr[i]<=arr[i+1]){
                return false;
            }
        }
        return true;

    }

