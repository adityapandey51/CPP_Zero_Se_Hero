#include<iostream>
using namespace std;
int binary_search(int arr[],int size,int element){
    int start=0;
    int end=size-1;
    int mid=start+((end-start)/2);
    while(start<=end){
        if (arr[mid]==element){
            return mid;
        }
        if (arr[mid]>element){
            end=mid-1;
        }
        if (arr[mid]<element){
            start=mid+1;
        }

        mid=start+((end-start)/2);
    }
    return -1;
}

// int main(){
//     int arr[6]={1,2,3,4,5,6};
//     int index=binary_search(arr,6,10);
//     cout<<index;
// }

// BINARY SEARCH PROBLEMS

// PROBLEM 1
// you have been given a sorted array of length n, u need to
// find the first and last most occurence index of an element

vector<int> first_last_occurence(int arr[],int size, int element){
    int first=-1;
    int last=-1;
    int i=0;
    vector<int> ans;
    while(i<size){
        if(arr[i]==element){
            if (first==-1){
                first=i;
                last=i;
            }
            else{
                last++;
            }
        }
        i++;
    }
    ans.push_back(first);
    ans.push_back(last);
    return ans;

}

// another approach

int first_index(int arr[];int size;int element){
    int start=0;
    int end=size-1;
    int mid=start+((end-start)/2);
    int ans;
    while(start<=end){
        if(arr[mid]==element){
          ans=mid;
          end=mid-1;
        }
        else if (arr[mid]>element){
           end=mid-1;
        }
        else if(arr[mid]<element){
           start=mid+1;
        }
        mid=start+((end-start)/2);
    }
    return ans;
}

int last_index(int arr[];int size;int element){
    int start=0;
    int end=size-1;
    int mid=start+((end-start)/2);
    int ans;
    while(start<=end){
        if(arr[mid]==element){
          ans=mid;
          start=mid+1;
        }
        else if (arr[mid]>element){
           end=mid-1;
        }
        else if(arr[mid]<element){
           start=mid+1;
        }
        mid=start+((end-start)/2);
    }
    return ans;
}
