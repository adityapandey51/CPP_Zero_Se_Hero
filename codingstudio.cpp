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