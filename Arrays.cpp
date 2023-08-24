#include <iostream>
using namespace std;


// Minimum in an array
int get_min(int arr[],int size){
    int mini=INT_MAX;
    for (int i=0;i<size;i++){
      mini=min(mini,arr[i]);
    }
    return mini;
}

// Maximum in an array

int get_max(int arr[],int size){
    int maxi=INT_MIN;
    for(int i=0;i<size;i++){
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}

// sum of elements of an array

int sum_of_elements(int arr[],int size){
    int sum =0;
    for (int i=0;i<size;i++){
        sum +=arr[i];
    }
    return sum;

}

// Reverse an  array

void reverse(int arr[],int size){
    int start=0;
    int end=size-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
 for (int i=0;i<size;i++){
    cout<<arr[i];
 }
}

// int main(){
//     int arr[6]={1,2,3,4,5,6};
//     reverse(arr,6);
// }

// Reverse aternate elements in an array

void reverse_alternate(int arr[],int size){
    int i=0;
    while(i+1<size){
        swap(arr[i],arr[i+1]);
        i=i+2;
    }
     for (int i=0;i<size;i++){
    cout<<arr[i];
 }
}

// int main(){
//     int arr[6]={1,2,3,4,5,6};
//     reverse_alternate(arr,6);
// }


// you have been given an integer arr of size N; where N =2M+1,
// Now in the given arr 'M' no's are present twice and one number is present only once
// You need to find and return theat no. which is unique in that arr

int unique(int arr[],int size){
    int sol=0;
    for (int i=0;i<size;i++){
        sol=sol^arr[i];
    }
    return sol;
}

// int main(){
//     int arr[9]={1,1,2,2,3,4,4,5,3};
//     int a=unique(arr,9);
//     cout<<a;
// }


// Intersection of __ARRAY_(sorted ones)

vector<int> Intersection_array(int arr1[],int arr2[],int size1,int size2){
    vector<int> ans;
    for (int i=0;i<size1;i++){
        for (int j=0;j<size2;j++){
            if (arr1[i]<arr2[j]){
                break;
            }
            if (arr1[i]=arr2[j]){
                ans.push_back(arr1[i]);
                arr2[j]=INT_MIN;
                break;
            }
        }
    }
    return ans;
}

// optimised version

vector<int> Intersection_array(int arr1[],int arr2[],int size1,int size2){
    vector<int> ans;
    int i=0;
    int j=0;
   while(i<size1 && j<size2){
    while(arr1[i]<arr2[j]){
        i++;
    }
    while(arr1[i]==arr2[j]){
        ans.push_back(arr1[j]);
        i++;
        j++;
    }
    while(arr1[i]>arr2[j]){
        j++;
    }

   }
    return ans;
}

// Pair sum

vector<vector<int>> pair_sum(int arr[],int size,int add){
    vector<vector<int>> ans;
     for (int i=0;i<size;i++){
        for (int j=i+1;j<size;j++){
            if (arr[i]+arr[j]==add){
                 vector<int> temp;
                 temp.push_back(min(arr[i],arr[j]));
                 temp.push_back(max(arr[i],arr[j]));
                 ans.push_back(temp);
            }
        }
     }
     sort(ans.begin(),ans.end())
     return ans;
}

// triplet sum

// sort 01

void sort_01(int arr[],int size){
    int start=0;
    int end=size-1;
    while(start<end){
      while (arr[start]==0 && start<end){
        start++;
      }
       while (arr[end]==1 && start<end){
        end--;
      }
       if(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
      }
    }
}