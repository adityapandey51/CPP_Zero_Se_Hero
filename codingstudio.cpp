// painters partition problem
#include<iostream>
using namespace std;
#include <vector>


bool ispossible(vector<int> &boards,int mid,int k){
    int painter=1;
    int sum=0;
    for(int i=0;i<boards.size();i++){
        if(sum+boards[i]<=mid){
            sum=sum+boards[i];
        }
        else{
            painter++;
            if(painter>k ||boards[i]>mid){
                return false;
            }
            sum=boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s=0;
    int e=0;
    for (int i=0;i<boards.size();i++){
        e=e+boards[i];
    }
    int mid=s+((e-s)/2);
    int ans;
    while(s<=e){
        if(ispossible(boards,mid,k)){
            ans=mid;
            e=mid-1;
            
        }
        else{
            s=mid+1;
        }
        mid=s+((e-s)/2);
    }
    return ans;
}

// aggressive cows

bool ispossible(vector<int>stalls,int mid,int k){
    int cowcount=1;
    int pos1=stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-pos1>=mid){
            cowcount++;
            if(cowcount==k){
                return true;
            }
            pos1=stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int s=0;
    int min=stalls[0];
    for (int i=1;i<stalls.size();i++){
        if (stalls[i]<min){
            min=stalls[i];
        }
    }
    int max=stalls[0];
     for (int i=1;i<stalls.size();i++){
        if (stalls[i]>min){
            max=stalls[i];
        }
    }
    int e=max-min;
    int mid=s+((e-s)/2);
    int ans;

    while(s<=e){
        if(ispossible(stalls,mid,k)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+((e-s)/2);
    }
    return ans;
}

// duplicate in a array

int findDuplicate(vector<int> &arr) 
{
     int ans=0;
     for (int i=0;i<arr.size();i++){
         ans=ans^arr[i];
     }
     for (int i=0;i<arr.size();i++){
         ans =ans^i;
     }
	return ans;
}

// intersection of arrays
#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int> ans;
	int i=0;
	int j=0;
	while(i<n && j<m){
		if (arr1[i]<arr2[j]){
			i++;
		}else if (arr1[i]>arr2[j]){
			j++;
		}else{
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
	}
	return ans;
}

// Duplicate in an array
//coding ninjas
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

// triplet sum

#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>> ans;
	
    sort(arr.begin(),arr.end());
    for (int i=0;i<n;i++){
        int l=i+1;
        int r=n-1;
        while(l<r){
            vector<int> temp;
            if (arr[i]+arr[l]+arr[r]==K){  
                temp.push_back(arr[i]);
                temp.push_back(arr[l]);
                temp.push_back(arr[r]);
                ans.push_back(temp);
                l++;
                r--;
            }else if(arr[i]+arr[l]+arr[r]<K){
                l++;
            }else{
                r--;
            }
        }
    }
    return ans;
}

// sort 0s 1s 2s

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int low=0;
   int mid=0;
   int hi=n-1;
   while(mid<=hi){
      if (arr[mid]==0){
         swap(arr[low++],arr[mid++]);
      }else if (arr[mid]==1){
         mid++;
      }else{
         swap(arr[hi--],arr[mid]);
      }
   }
}